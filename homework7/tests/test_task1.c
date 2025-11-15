#include "listutils.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void test_append_find_insert() {
    c_list* l = create_list(5);
    int a = 10, b = 20, c = 30;
    l->append(l, &a, LIST_INT);
    l->append(l, &b, LIST_INT);
    l->append(l, &c, LIST_INT);
    assert(l->find_index(l, &b, LIST_INT) == 1);
    int ins = 99;
    l->insert(l, 1, &ins, LIST_INT);
    assert(l->size == 4);
    l->destroy(l);
    printf("test_append_find_insert OK\n");
}

void test_find_not_found() {
    c_list* l = create_list(5);
    int a = 5;
    l->append(l, &a, LIST_INT);
    int search = 999;
    assert(l->find_index(l, &search, LIST_INT) == -1);
    l->destroy(l);
    printf("test_find_not_found OK\n");
}

void test_insert_bounds() {
    c_list* l = create_list(5);
    int a = 1;
    l->append(l, &a, LIST_INT);
    assert(l->insert(l, 10, &a, LIST_INT) == -1);
    l->destroy(l);
    printf("test_insert_bounds OK\n");
}

void test_pop_empty() {
    c_list* l = create_list(5);
    assert(l->pop(l) == -1);
    l->destroy(l);
    printf("test_pop_empty OK\n");
}

void test_mixed_types() {
    c_list* l = create_list(5);
    int a = 42;
    float b = 3.17;
    char* c = "test";
    l->append(l, &a, LIST_INT);
    l->append(l, &b, LIST_FLOAT);
    l->append(l, c, LIST_STRING);
    assert(l->size == 3);
    assert(l->find_index(l, &a, LIST_INT) == 0);
    assert(l->find_index(l, &b, LIST_FLOAT) == 1);
    l->destroy(l);
    printf("test_mixed_types OK\n");
}

void test_null_checks() {
    c_list* l = create_list(5);
    assert(l->append(l, NULL, LIST_INT) == -1);
    assert(l->find_index(l, NULL, LIST_INT) == -1);
    assert(l->insert(l, 0, NULL, LIST_INT) == -1);
    l->destroy(l);
    printf("test_null_checks OK\n");
}

int main(void) {
    test_append_find_insert();
    test_find_not_found();
    test_insert_bounds();
    test_pop_empty();
    test_mixed_types();
    test_null_checks();
    printf("\nAll task1 tests passed!\n");
    return 0;
}
