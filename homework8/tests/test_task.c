#include <CUnit/Basic.h>
#include "listutils.h"

void test_append_int() {
    c_list* l = create_list(2);
    CU_ASSERT(append_list(l, "d", 99) == 0);
    CU_ASSERT(size_list(l) == 1);
    destroy_list(l);
}

void test_append_float() {
    c_list* l = create_list(2);
    CU_ASSERT(append_list(l, "f", 3.14f) == 0);
    CU_ASSERT(size_list(l) == 1);
    destroy_list(l);
}

void test_append_string() {
    c_list* l = create_list(2);
    CU_ASSERT(append_list(l, "s", "vasyll") == 0);
    CU_ASSERT(size_list(l) == 1);
    destroy_list(l);
}

void test_append_null() {
    CU_ASSERT(append_list(NULL, "d", 1) == -1);
}

void test_invalid_format() {
    c_list* l = create_list(2);
    CU_ASSERT(append_list(l, "x", 1) == -1);
    destroy_list(l);
}

void test_out_of_bounds() {
    c_list* l = create_list(1);
    append_list(l, "d", 1);
    print_element(l, 999);
    destroy_list(l);
}

void test_zero_capacity() {
    c_list* l = create_list(0);
    CU_ASSERT_PTR_NOT_NULL(l);
    append_list(l, "d", 1);
    CU_ASSERT(size_list(l) == 1);
    destroy_list(l);
}

void test_multiple_elements() {
    c_list* l = create_list(2);
    append_list(l, "d", 1);
    append_list(l, "f", 1.5f);
    append_list(l, "s", "str");
    CU_ASSERT(size_list(l) == 3);
    destroy_list(l);
}

void test_dump_and_load() {
    c_list* l = create_list(3);
    append_list(l, "d", 42);
    append_list(l, "f", 3.0f);
    append_list(l, "s", "abc");
    dump_list_to_file(l, "test.txt");
    c_list* loaded = create_list_from_file("test.txt");
    CU_ASSERT(size_list(loaded) == 3);
    destroy_list(l);
    destroy_list(loaded);
    remove("test.txt");
}

void test_get_element_by_index() {
    c_list* l = create_list(3);
    append_list(l, "d", 123);         
    append_list(l, "f", 7.77f);        
    append_list(l, "s", "arthas");       

    CU_ASSERT(*(int*)get_element_by_index(l, 0) == 123);
    CU_ASSERT_DOUBLE_EQUAL(*(float*)get_element_by_index(l, 1), 7.77f, 0.0001);
    CU_ASSERT_STRING_EQUAL((char*)get_element_by_index(l, 2), "arthas");

    destroy_list(l);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("list_tests", NULL, NULL);

    CU_add_test(suite, "append int", test_append_int);
    CU_add_test(suite, "append float", test_append_float);
    CU_add_test(suite, "append string", test_append_string);
    CU_add_test(suite, "append null", test_append_null);
    CU_add_test(suite, "invalid format", test_invalid_format);
    CU_add_test(suite, "out of bounds", test_out_of_bounds);
    CU_add_test(suite, "zero capacity", test_zero_capacity);
    CU_add_test(suite, "multiple elements", test_multiple_elements);
    CU_add_test(suite, "dump and load", test_dump_and_load);
    CU_add_test(suite, "get element by index", test_get_element_by_index); // ДОДАНО!

    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
