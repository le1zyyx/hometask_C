#include "listutils.h"
#include <stdio.h>

int main(void) {
    void** listA = create_list();
    void** listB = create_list();
    
    int a = 5;
    float b = 3.14f;
    char* c = "hello";
    
    append_list(listA, &a, LIST_INT);
    append_list(listA, &b, LIST_FLOAT);
    append_list(listA, c, LIST_STRING);
    
    printf("List A:\n");
    print_list(listA);
    printf("A size: %zu, capacity: %zu\n\n", get_list_size(listA), get_list_capacity(listA));
    
    int x = 10;
    char* y = "world";
    append_list(listB, &x, LIST_INT);
    append_list(listB, y, LIST_STRING);
    
    printf("List B:\n");
    print_list(listB);
    printf("B size: %zu, capacity: %zu\n\n", get_list_size(listB), get_list_capacity(listB));
    
    printf("Popped last element from List A\n");
    pop_list(listA);
    
    printf("List A after pop:\n");
    print_list(listA);
    printf("A size: %zu\n\n", get_list_size(listA));
    
    free_list(listA);
    free_list(listB);
    
    return 0;
}
