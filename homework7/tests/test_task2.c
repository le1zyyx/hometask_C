#include "listutils.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void test_dump_and_load_int() {
    c_list* l = create_list(5);
    int a = 42, b = -10, c = 100;
    l->append(l, &a, LIST_INT);
    l->append(l, &b, LIST_INT);
    l->append(l, &c, LIST_INT);
    dump_list_to_file(l, "test_int.txt");
    c_list* loaded = create_list_from_file("test_int.txt");
    assert(loaded->size == 3);
    assert(loaded->find_index(loaded, &a, LIST_INT) == 0);
    assert(loaded->find_index(loaded, &b, LIST_INT) == 1);
    assert(loaded->find_index(loaded, &c, LIST_INT) == 2);
    l->destroy(l);
    loaded->destroy(loaded);
    unlink("test_int.txt");
    printf("test_dump_and_load_int OK\n");
}

void test_dump_and_load_float() {
    c_list* l = create_list(5);
    float a = 3.14f, b = 2.71f, c = 1.41f;
    l->append(l, &a, LIST_FLOAT);
    l->append(l, &b, LIST_FLOAT);
    l->append(l, &c, LIST_FLOAT);
    dump_list_to_file(l, "test_float.txt");
    c_list* loaded = create_list_from_file("test_float.txt");
    assert(loaded->size == 3);
    l->destroy(l);
    loaded->destroy(loaded);
    unlink("test_float.txt");
    printf("test_dump_and_load_float OK\n");
}

void test_dump_and_load_string() {
    c_list* l = create_list(5);
    char* a = "hello";
    char* b = "world";
    char* c = "test";
    l->append(l, a, LIST_STRING);
    l->append(l, b, LIST_STRING);
    l->append(l, c, LIST_STRING);
    dump_list_to_file(l, "test_string.txt");
    c_list* loaded = create_list_from_file("test_string.txt");
    assert(loaded->size == 3);
    assert(loaded->find_index(loaded, a, LIST_STRING) == 0);
    assert(loaded->find_index(loaded, b, LIST_STRING) == 1);
    assert(loaded->find_index(loaded, c, LIST_STRING) == 2);
    l->destroy(l);
    loaded->destroy(loaded);
    unlink("test_string.txt");
    printf("test_dump_and_load_string OK\n");
}

void test_dump_and_load_mixed() {
    c_list* l = create_list(5);
    int a = 99;
    float b = 7.77f;
    char* c = "mixed";
    l->append(l, &a, LIST_INT);
    l->append(l, &b, LIST_FLOAT);
    l->append(l, c, LIST_STRING);
    dump_list_to_file(l, "test_mixed.txt");
    c_list* loaded = create_list_from_file("test_mixed.txt");
    assert(loaded->size == 3);
    assert(loaded->find_index(loaded, &a, LIST_INT) == 0);
    assert(loaded->find_index(loaded, &b, LIST_FLOAT) == 1);
    assert(loaded->find_index(loaded, c, LIST_STRING) == 2);
    l->destroy(l);
    loaded->destroy(loaded);
    unlink("test_mixed.txt");
    printf("test_dump_and_load_mixed OK\n");
}

void test_load_empty_file() {
    c_list* l = create_list(5);
    dump_list_to_file(l, "test_empty.txt");
    c_list* loaded = create_list_from_file("test_empty.txt");
    assert(loaded->size == 0);
    l->destroy(l);
    loaded->destroy(loaded);
    unlink("test_empty.txt");
    printf("test_load_empty_file OK\n");
}

void test_load_nonexistent_file() {
    c_list* loaded = create_list_from_file("nonexistent_file_xyz.txt");
    assert(loaded == NULL);
    printf("test_load_nonexistent_file OK\n");
}

int main(void) {
    test_dump_and_load_int();
    test_dump_and_load_float();
    test_dump_and_load_string();
    test_dump_and_load_mixed();
    test_load_empty_file();
    test_load_nonexistent_file();
    printf("\nAll task2 tests passed!\n");
    return 0;
}
