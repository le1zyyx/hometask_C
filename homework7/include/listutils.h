#ifndef LISTUTILS_H
#define LISTUTILS_H
#include <stddef.h>

typedef enum { LIST_INT, LIST_FLOAT, LIST_STRING } list_data_type;

typedef struct c_list {
    void** data;
    list_data_type* types;
    size_t size;
    size_t capacity;
    
    int (*append)(struct c_list* l, void* item, list_data_type t);
    int (*pop)(struct c_list* l);
    void (*print)(struct c_list* l);
    int (*find_index)(const struct c_list* l, void* item, list_data_type t);
    int (*insert)(struct c_list* l, size_t pos, void* item, list_data_type t);
    void (*destroy)(struct c_list* l);
} c_list;

c_list* create_list(size_t capacity);
c_list* create_list_from_file(const char *filename);
int dump_list_to_file(const c_list *list, const char *filename);

#endif
