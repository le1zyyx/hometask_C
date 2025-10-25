#include "listutils.h"
#include <stdio.h>

int main() {
    void** mylist = create_list();
    
    int a = 5;
    float b = 3.14f;
    char* c = "hello";
    
    append_list(mylist, &a, LIST_INT);
    append_list(mylist, &b, LIST_FLOAT);
    append_list(mylist, c, LIST_STRING);
    
    print_list(mylist);
    
    printf("Current size: %zu\n", get_list_size(mylist));
    printf("Capacity: %zu\n", get_list_capacity());
    
    return 0;
}
