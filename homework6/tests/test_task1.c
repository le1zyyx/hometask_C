#include "listutils.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

void test_create(void) {
    void** list = create_list();
    assert(list != NULL);
    assert(get_list_size(list) == 0);
    assert(get_list_capacity(list) > 0);
    free_list(list);
    printf("Test create: PASS\n");
}

void test_append_all_types(void) {
    void** list = create_list();
    int a = 42;
    float b = 3.14f;
    char* c = "hello";
    
    assert(append_list(list, &a, LIST_INT) == 0);
    assert(append_list(list, &b, LIST_FLOAT) == 0);
    assert(append_list(list, c, LIST_STRING) == 0);
    assert(get_list_size(list) == 3);
    free_list(list);
    printf("Test append all types: PASS\n");
}

void test_pop_and_shrink(void) {
    void** list = create_list();
    int values[10];
    for (int i = 0; i < 10; i++) {
        values[i] = i;
        append_list(list, &values[i], LIST_INT);
    }
    assert(get_list_size(list) == 10);
    for (int i = 0; i < 10; i++) {
        assert(pop_list(list) == 0);
    }
    assert(get_list_size(list) == 0);
    free_list(list);
    printf("Test pop and shrink: PASS\n");
}

void test_multiple_lists(void) {
    void** list1 = create_list();
    void** list2 = create_list();
    int a = 1;
    int b = 2;
    append_list(list1, &a, LIST_INT);
    append_list(list2, &b, LIST_INT);
    assert(get_list_size(list1) == 1);
    assert(get_list_size(list2) == 1);
    free_list(list1);
    free_list(list2);
    printf("Test multiple lists: PASS\n");
}

void test_error_cases(void) {
    void** list = create_list();
    assert(pop_list(NULL) == -1);
    assert(pop_list(list) == -1);
    assert(append_list(NULL, &list, LIST_INT) == -1);
    assert(get_list_size(NULL) == 0);
    free_list(list);
    printf("Test error cases: PASS\n");
}

int main(void) {
    test_create();
    test_append_all_types();
    test_pop_and_shrink();
    test_multiple_lists();
    test_error_cases();
    printf("\nAll tests passed!\n");
    return 0;
}
