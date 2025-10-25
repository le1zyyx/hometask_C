#ifndef LISTUTILS_H
#define LISTUTILS_H
#include <stddef.h>

typedef enum {
    LIST_INT,
    LIST_FLOAT,
    LIST_STRING
} list_data_type;

void** create_list(void);
int append_list(void** list, void* item, list_data_type type);
void print_list(void** list);
size_t get_list_size(void** list);
size_t get_list_capacity(void);

#endif
