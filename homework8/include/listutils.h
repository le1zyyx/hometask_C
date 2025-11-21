#ifndef LISTUTILS_H
#define LISTUTILS_H
#include <stddef.h>

typedef struct c_list c_list;

c_list* create_list(size_t capacity);
void destroy_list(c_list* l);
int append_list(c_list* list, const char* fmt, ...);
void print_element(const c_list* list, size_t index);
void print_list(const c_list* l);
size_t size_list(const c_list* l);
c_list* create_list_from_file(const char *filename);
int dump_list_to_file(const c_list *list, const char *filename);
void* get_element_by_index(const c_list* list, size_t idx);

#endif
