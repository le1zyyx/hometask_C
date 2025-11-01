#include "listutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

typedef struct {
    void** data;
    list_data_type* types;
    size_t size;
    size_t capacity;
} List;

void** create_list(void) {
    List* list = malloc(sizeof(List));
    if (!list) return NULL;
    
    list->data = malloc(INITIAL_CAPACITY * sizeof(void*));
    list->types = malloc(INITIAL_CAPACITY * sizeof(list_data_type));
    if (!list->data || !list->types) {
        free(list->data);
        free(list->types);
        free(list);
        return NULL;
    }
    
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    
    return (void**)list;
}

int append_list(void** list, void* item, list_data_type type) {
    if (!list) return -1;
    
    List* l = (List*)list;
    
    if (l->size >= l->capacity) {
        size_t new_capacity = l->capacity * 2;
        void** new_data = realloc(l->data, new_capacity * sizeof(void*));
        list_data_type* new_types = realloc(l->types, new_capacity * sizeof(list_data_type));
        
        if (!new_data || !new_types) {
            free(new_data);
            free(new_types);
            return -1;
        }
        
        l->data = new_data;
        l->types = new_types;
        l->capacity = new_capacity;
    }
    
    l->types[l->size] = type;
    
    if (type == LIST_INT) {
        int* p = malloc(sizeof(int));
        if (!p) return -1;
        *p = *(int*)item;
        l->data[l->size] = p;
    } else if (type == LIST_FLOAT) {
        float* p = malloc(sizeof(float));
        if (!p) return -1;
        *p = *(float*)item;
        l->data[l->size] = p;
    } else if (type == LIST_STRING) {
        char* p = malloc(strlen((char*)item) + 1);
        if (!p) return -1;
        strcpy(p, (char*)item);
        l->data[l->size] = p;
    }
    
    l->size++;
    return 0;
}

void print_list(void** list) {
    if (!list) return;
    
    List* l = (List*)list;
    printf("List size = %zu\n", l->size);
    
    for (size_t i = 0; i < l->size; i++) {
        if (l->types[i] == LIST_INT)
            printf("%d ", *(int*)l->data[i]);
        else if (l->types[i] == LIST_FLOAT)
            printf("%f ", *(float*)l->data[i]);
        else if (l->types[i] == LIST_STRING)
            printf("%s ", (char*)l->data[i]);
    }
    printf("\n");
}

size_t get_list_size(void** list) {
    if (!list) return 0;
    List* l = (List*)list;
    return l->size;
}

size_t get_list_capacity(void** list) {
    if (!list) return 0;
    List* l = (List*)list;
    return l->capacity;
}

int pop_list(void** list) {
    if (!list) return -1;
    
    List* l = (List*)list;
    if (l->size == 0) return -1;
    
    l->size--;
    free(l->data[l->size]);
    
    if (l->size < l->capacity / 4 && l->capacity > INITIAL_CAPACITY) {
        size_t new_capacity = l->capacity / 2;
        void** new_data = realloc(l->data, new_capacity * sizeof(void*));
        list_data_type* new_types = realloc(l->types, new_capacity * sizeof(list_data_type));
        
        if (new_data && new_types) {
            l->data = new_data;
            l->types = new_types;
            l->capacity = new_capacity;
        }
    }
    
    return 0;
}

void free_list(void** list) {
    if (!list) return;
    
    List* l = (List*)list;
    
    for (size_t i = 0; i < l->size; i++) {
        free(l->data[i]);
    }
    
    free(l->data);
    free(l->types);
    free(l);
}
