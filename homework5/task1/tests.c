#include "listutils.h"
#include <stdio.h>
#include <string.h>

void test_happy_add() {
    void** list = create_list();
    int i = 1;
    float f = 2.5;
    char s[] = "test";
    int res_i = append_list(list, &i, LIST_INT);
    int res_f = append_list(list, &f, LIST_FLOAT);
    int res_s = append_list(list, s, LIST_STRING);
    printf("%s\n", (res_i == 0 && res_f == 0 && res_s == 0) ? "PASS" : "FAIL");
}

void test_overflow() {
    void** list = create_list();
    int v = 5;
    int ok = 1;
    for (int i = 0; i < 100; ++i) {
        if (append_list(list, &v, LIST_INT) != 0) ok = 0;
    }
    printf("%s\n", (append_list(list, &v, LIST_INT) == -1 && ok) ? "PASS" : "FAIL");
}

void test_string_value() {
    void** list = create_list();
    char s[] = "hello";
    append_list(list, s, LIST_STRING);
    printf("%s\n", (get_list_size(list) == 1) ? "PASS" : "FAIL");
}

void test_float_value() {
    void** list = create_list();
    float f = 1.77;
    append_list(list, &f, LIST_FLOAT);
    printf("%s\n", (get_list_size(list) == 1) ? "PASS" : "FAIL");
}

void test_empty() {
    void** list = create_list();
    printf("%s\n", (get_list_size(list) == 0) ? "PASS" : "FAIL");
}

int main() {
    test_happy_add();
    test_overflow();
    test_string_value();
    test_float_value();
    test_empty();
    return 0;
}
