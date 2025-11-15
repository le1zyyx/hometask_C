#include "listutils.h"
#include <stdio.h>

int main(void) {
    c_list* list = create_list(2);
    
    int a = -6;
    float b = 0.1f;
    
    list->append(list, &a, LIST_INT);
    list->append(list, &b, LIST_FLOAT);
    
    printf("Original list:\n");
    list->print(list);
    
    list->pop(list);
    printf("List after pop:\n");
    list->print(list);
    
    dump_list_to_file(list, "list.txt");
    
    c_list* loaded = create_list_from_file("list.txt");
    printf("Loaded from file:\n");
    loaded->print(loaded);
    
    list->destroy(list);
    loaded->destroy(loaded);
    
    return 0;
}
