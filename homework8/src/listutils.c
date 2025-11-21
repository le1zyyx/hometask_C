#include "listutils.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define INIT_CAP 10

typedef enum { INT_T, FLOAT_T, STR_T } valtype;

struct c_list {
    void** data;
    valtype* types;
    size_t size;
    size_t cap;
};

c_list* create_list(size_t capacity) {
    if (!capacity) capacity = INIT_CAP;
    c_list* l = malloc(sizeof(c_list));
    l->data = malloc(capacity * sizeof(void*));
    l->types = malloc(capacity * sizeof(valtype));
    l->size = 0;
    l->cap = capacity;
    return l;
}

void destroy_list(c_list* l) {
    if (!l) return;
    for (size_t i = 0; i < l->size; i++) free(l->data[i]);
    free(l->data);
    free(l->types);
    free(l);
}

int append_list(c_list* list, const char* fmt, ...) {
    if (!list || !fmt) return -1;
    if (list->size >= list->cap) {
        size_t ncap = list->cap * 2;
        list->data = realloc(list->data, ncap * sizeof(void*));
        list->types = realloc(list->types, ncap * sizeof(valtype));
        list->cap = ncap;
    }
    va_list args;
    va_start(args, fmt);
    if (strcmp(fmt, "d") == 0) {
        int val = va_arg(args, int);
        int* p = malloc(sizeof(int));
        *p = val;
        list->data[list->size] = p;
        list->types[list->size] = INT_T;
    } else if (strcmp(fmt, "f") == 0) {
        double val = va_arg(args, double);
        float* p = malloc(sizeof(float));
        *p = (float)val;
        list->data[list->size] = p;
        list->types[list->size] = FLOAT_T;
    } else if (strcmp(fmt, "s") == 0) {
        char* val = va_arg(args, char*);
        char* p = malloc(strlen(val)+1);
        strcpy(p, val);
        list->data[list->size] = p;
        list->types[list->size] = STR_T;
    } else {
        va_end(args);
        return -1;
    }
    list->size++;
    va_end(args);
    return 0;
}

void print_element(const c_list* list, size_t idx) {
    if (!list || idx >= list->size) return;
    printf("Index %zu = ", idx);
    if (list->types[idx] == INT_T) printf("%d\n", *(int*)list->data[idx]);
    else if (list->types[idx] == FLOAT_T) printf("%f\n", *(float*)list->data[idx]);
    else printf("%s\n", (char*)list->data[idx]);
}

void* get_element_by_index(const c_list* list, size_t idx) {
    if (!list || idx >=list ->size) return NULL;
    return list->data[idx];

}

void print_list(const c_list* l) {
    if (!l) return;
    for (size_t i = 0; i < l->size; i++) {
        if (l->types[i] == INT_T) printf("%d ", *(int*)l->data[i]);
        else if (l->types[i] == FLOAT_T) printf("%f ", *(float*)l->data[i]);
        else printf("%s ", (char*)l->data[i]);
    }
    printf("\n");
}

size_t size_list(const c_list* l) {
    return l ? l->size : 0;
}

c_list* create_list_from_file(const char *filename) {
    FILE* f = fopen(filename, "r");
    if (!f) return NULL;
    c_list* l = create_list(INIT_CAP);
    char line[256], val[200], type[10];
    while (fgets(line, sizeof(line), f)) {
        if (sscanf(line, "%s %s", type, val) == 2) {
            if (!strcmp(type, "int")) {
                int x = atoi(val);
                append_list(l, "d", x);
            } else if (!strcmp(type, "float")) {
                float x = atof(val);
                append_list(l, "f", x);
            } else if (!strcmp(type, "string")) {
                append_list(l, "s", val);
            }
        }
    }
    fclose(f);
    return l;
}

int dump_list_to_file(const c_list *list, const char *filename) {
    if (!list || !filename) return -1;
    FILE* f = fopen(filename, "w");
    if (!f) return -1;
    for (size_t i = 0; i < list->size; i++) {
        if (list->types[i] == INT_T) fprintf(f, "int %d\n", *(int*)list->data[i]);
        else if (list->types[i] == FLOAT_T) fprintf(f, "float %f\n", *(float*)list->data[i]);
        else fprintf(f, "string %s\n", (char*)list->data[i]);
    }
    fclose(f);
    return 0;
}
