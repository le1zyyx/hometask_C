#include "listutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_CAP 10

static int append_impl(c_list* l, void* item, list_data_type t) {
    if (!l || !item) return -1;
    
    if (l->size >= l->capacity) {
        void** nd = realloc(l->data, (l->capacity * 2) * sizeof(void*));
        list_data_type* nt = realloc(l->types, (l->capacity * 2) * sizeof(list_data_type));
        if (!nd || !nt) return -1;
        l->data = nd;
        l->types = nt;
        l->capacity *= 2;
    }
    
    l->types[l->size] = t;
    if (t == LIST_INT) {
        int* p = malloc(sizeof(int));
        if (!p) return -1;
        *p = *(int*)item;
        l->data[l->size] = p;
    } else if (t == LIST_FLOAT) {
        float* p = malloc(sizeof(float));
        if (!p) return -1;
        *p = *(float*)item;
        l->data[l->size] = p;
    } else {
        char* p = malloc(strlen((char*)item) + 1);
        if (!p) return -1;
        strcpy(p, (char*)item);
        l->data[l->size] = p;
    }
    l->size++;
    return 0;
}

static int pop_impl(c_list* l) {
    if (!l || l->size == 0) return -1;
    l->size--;
    free(l->data[l->size]);
    return 0;
}

static void print_impl(c_list* l) {
    if (!l) return;
    printf("[");
    for (size_t i = 0; i < l->size; i++) {
        if (l->types[i] == LIST_INT) printf("%d", *(int*)l->data[i]);
        else if (l->types[i] == LIST_FLOAT) printf("%g", *(float*)l->data[i]);
        else printf("%s", (char*)l->data[i]);
        if (i < l->size - 1) printf(", ");
    }
    printf("]\n");
}

static int find_index_impl(const c_list* l, void* item, list_data_type t) {
    if (!l || !item) return -1;
    for (size_t i = 0; i < l->size; i++) {
        if (l->types[i] != t) continue;
        if (t == LIST_INT && *(int*)l->data[i] == *(int*)item) return i;
        else if (t == LIST_FLOAT && *(float*)l->data[i] == *(float*)item) return i;
        else if (t == LIST_STRING && strcmp((char*)l->data[i], (char*)item) == 0) return i;
    }
    return -1;
}

static int insert_impl(c_list* l, size_t pos, void* item, list_data_type t) {
    if (!l || !item || pos > l->size) return -1;
    
    if (l->size >= l->capacity) {
        void** nd = realloc(l->data, (l->capacity * 2) * sizeof(void*));
        list_data_type* nt = realloc(l->types, (l->capacity * 2) * sizeof(list_data_type));
        if (!nd || !nt) return -1;
        l->data = nd;
        l->types = nt;
        l->capacity *= 2;
    }
    
    for (size_t i = l->size; i > pos; i--) {
        l->data[i] = l->data[i - 1];
        l->types[i] = l->types[i - 1];
    }
    
    l->types[pos] = t;
    if (t == LIST_INT) {
        int* p = malloc(sizeof(int));
        if (!p) return -1;
        *p = *(int*)item;
        l->data[pos] = p;
    } else if (t == LIST_FLOAT) {
        float* p = malloc(sizeof(float));
        if (!p) return -1;
        *p = *(float*)item;
        l->data[pos] = p;
    } else {
        char* p = malloc(strlen((char*)item) + 1);
        if (!p) return -1;
        strcpy(p, (char*)item);
        l->data[pos] = p;
    }
    l->size++;
    return 0;
}

static void destroy_impl(c_list* l) {
    if (!l) return;
    for (size_t i = 0; i < l->size; i++) free(l->data[i]);
    free(l->data);
    free(l->types);
    free(l);
}

c_list* create_list(size_t capacity) {
    if (capacity == 0) capacity = INIT_CAP;
    
    c_list* l = malloc(sizeof(c_list));
    if (!l) return NULL;
    
    l->data = malloc(capacity * sizeof(void*));
    l->types = malloc(capacity * sizeof(list_data_type));
    if (!l->data || !l->types) {
        free(l->data);
        free(l->types);
        free(l);
        return NULL;
    }
    
    l->size = 0;
    l->capacity = capacity;
    l->append = append_impl;
    l->pop = pop_impl;
    l->print = print_impl;
    l->find_index = find_index_impl;
    l->insert = insert_impl;
    l->destroy = destroy_impl;
    
    return l;
}

c_list* create_list_from_file(const char *filename) {
    if (!filename) return NULL;
    FILE* f = fopen(filename, "r");
    if (!f) return NULL;
    
    c_list* l = create_list(INIT_CAP);
    if (!l) { fclose(f); return NULL; }
    
    char line[256], type[20];
    while (fgets(line, sizeof(line), f)) {
        if (sscanf(line, "%s", type) != 1) continue;
        
        if (strcmp(type, "int") == 0) {
            int val;
            if (sscanf(line, "int %d", &val) == 1) l->append(l, &val, LIST_INT);
        } else if (strcmp(type, "float") == 0) {
            float val;
            if (sscanf(line, "float %f", &val) == 1) l->append(l, &val, LIST_FLOAT);
        } else if (strcmp(type, "string") == 0) {
            char val[200];
            if (sscanf(line, "string %199s", val) == 1) l->append(l, val, LIST_STRING);
        }
    }
    fclose(f);
    return l;
}

int dump_list_to_file(const c_list *l, const char *filename) {
    if (!l || !filename) return -1;
    FILE* f = fopen(filename, "w");
    if (!f) return -1;
    
    for (size_t i = 0; i < l->size; i++) {
        if (l->types[i] == LIST_INT) fprintf(f, "int %d\n", *(int*)l->data[i]);
        else if (l->types[i] == LIST_FLOAT) fprintf(f, "float %f\n", *(float*)l->data[i]);
        else fprintf(f, "string %s\n", (char*)l->data[i]);
    }
    fclose(f);
    return 0;
}
