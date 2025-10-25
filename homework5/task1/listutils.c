#include "listutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIST_CAPACITY 100

static void* global_list[LIST_CAPACITY];
static list_data_type global_types[LIST_CAPACITY];
static size_t global_size = 0;

void** create_list(void) {
    global_size = 0;
    return (void**)global_list;
}

int append_list(void** list, void* item, list_data_type type) {
    if (global_size >= LIST_CAPACITY)
        return -1;
    
    global_types[global_size] = type;
    
    if (type == LIST_INT) {
        int* p = (int*)malloc(sizeof(int));
        *p = *(int*)item;
        list[global_size] = p;
    } else if (type == LIST_FLOAT) {
        float* p = (float*)malloc(sizeof(float));
        *p = *(float*)item;
        list[global_size] = p;
    } else if (type == LIST_STRING) {
        char* p = (char*)malloc(strlen((char*)item) + 1);
        strcpy(p, (char*)item);
        list[global_size] = p;
    }
    
    global_size++;
    return 0;
}

void print_list(void** list) {
    for (size_t i = 0; i < global_size; i++) {
        if (global_types[i] == LIST_INT)
            printf("%d\n", *(int*)list[i]);
        else if (global_types[i] == LIST_FLOAT)
            printf("%f\n", *(float*)list[i]);
        else if (global_types[i] == LIST_STRING)
            printf("%s\n", (char*)list[i]);
    }
}

size_t get_list_size(void** list) {
    (void)list;
    return global_size;
}

size_t get_list_capacity(void) {
    return LIST_CAPACITY;
}
