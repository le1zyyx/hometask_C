#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "listutils.h"

void test_reverse_empty(void)
{
    struct List *head = NULL;
    head = reverse_list(head);
    CU_ASSERT_PTR_NULL(head);
}

void test_reverse_one(void)
{
    struct List *head = insert_back(NULL, 1);
    head = reverse_list(head);
    CU_ASSERT_EQUAL(head->item, 1);
    CU_ASSERT_PTR_NULL(head->next);
    free_list(head);
}

void test_reverse_two(void)
{
    struct List *head = insert_back(NULL, 1);
    insert_back(head, 2);
    head = reverse_list(head);
    CU_ASSERT_EQUAL(head->item, 2);
    CU_ASSERT_EQUAL(head->next->item, 1);
    CU_ASSERT_PTR_NULL(head->next->next);
    free_list(head);
}

void test_reverse_many(void)
{
    struct List *head = insert_back(NULL, 1);
    insert_back(head, 2);
    insert_back(head, 3);
    insert_back(head, 4);
    insert_back(head, 5);
    head = reverse_list(head);
    CU_ASSERT_EQUAL(head->item, 5);
    CU_ASSERT_EQUAL(head->next->item, 4);
    CU_ASSERT_EQUAL(head->next->next->item, 3);
    CU_ASSERT_EQUAL(head->next->next->next->item, 2);
    CU_ASSERT_EQUAL(head->next->next->next->next->item, 1);
    CU_ASSERT_PTR_NULL(head->next->next->next->next->next);
    free_list(head);
}

void test_reverse_negative(void)
{
    struct List *head = insert_back(NULL, -5);
    insert_back(head, 0);
    insert_back(head, 5);
    head = reverse_list(head);
    CU_ASSERT_EQUAL(head->item, 5);
    CU_ASSERT_EQUAL(head->next->item, 0);
    CU_ASSERT_EQUAL(head->next->next->item, -5);
    free_list(head);
}

void test_partition_empty(void)
{
    struct List *head = NULL;
    head = partition_list(head, 5);
    CU_ASSERT_PTR_NULL(head);
}

void test_partition_all_less(void)
{
    struct List *head = insert_back(NULL, 1);
    insert_back(head, 2);
    insert_back(head, 3);
    head = partition_list(head, 10);
    CU_ASSERT_EQUAL(head->item, 1);
    CU_ASSERT_EQUAL(head->next->item, 2);
    CU_ASSERT_EQUAL(head->next->next->item, 3);
    CU_ASSERT_PTR_NULL(head->next->next->next);
    free_list(head);
}

void test_partition_all_greater(void)
{
    struct List *head = insert_back(NULL, 10);
    insert_back(head, 15);
    insert_back(head, 20);
    head = partition_list(head, 5);
    CU_ASSERT_EQUAL(head->item, 10);
    CU_ASSERT_EQUAL(head->next->item, 15);
    CU_ASSERT_EQUAL(head->next->next->item, 20);
    CU_ASSERT_PTR_NULL(head->next->next->next);
    free_list(head);
}

void test_partition_example(void)
{
    struct List *head = insert_back(NULL, 3);
    insert_back(head, 5);
    insert_back(head, 8);
    insert_back(head, 5);
    insert_back(head, 10);
    insert_back(head, 2);
    insert_back(head, 1);

    head = partition_list(head, 5);

    CU_ASSERT_EQUAL(head->item, 3);
    CU_ASSERT_EQUAL(head->next->item, 2);
    CU_ASSERT_EQUAL(head->next->next->item, 1);
    CU_ASSERT_EQUAL(head->next->next->next->item, 5);
    CU_ASSERT_EQUAL(head->next->next->next->next->item, 8);
    CU_ASSERT_EQUAL(head->next->next->next->next->next->item, 5);
    CU_ASSERT_EQUAL(head->next->next->next->next->next->next->item, 10);
    CU_ASSERT_PTR_NULL(head->next->next->next->next->next->next->next);

    free_list(head);
}

void test_partition_negative(void)
{
    struct List *head = insert_back(NULL, -5);
    insert_back(head, 0);
    insert_back(head, 5);
    insert_back(head, -10);
    insert_back(head, 10);

    head = partition_list(head, 0);

    CU_ASSERT_EQUAL(head->item, -5);
    CU_ASSERT_EQUAL(head->next->item, -10);
    CU_ASSERT_EQUAL(head->next->next->item, 0);
    CU_ASSERT_EQUAL(head->next->next->next->item, 5);
    CU_ASSERT_EQUAL(head->next->next->next->next->item, 10);

    free_list(head);
}

void test_partition_one_less(void)
{
    struct List *head = insert_back(NULL, 3);
    head = partition_list(head, 5);
    CU_ASSERT_EQUAL(head->item, 3);
    CU_ASSERT_PTR_NULL(head->next);
    free_list(head);
}

void test_partition_one_greater(void)
{
    struct List *head = insert_back(NULL, 7);
    head = partition_list(head, 5);
    CU_ASSERT_EQUAL(head->item, 7);
    CU_ASSERT_PTR_NULL(head->next);
    free_list(head);
}

int main()
{
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    pSuite = CU_add_suite("Task 1: Reverse", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_add_test(pSuite, "empty", test_reverse_empty);
    CU_add_test(pSuite, "one", test_reverse_one);
    CU_add_test(pSuite, "two", test_reverse_two);
    CU_add_test(pSuite, "many", test_reverse_many);
    CU_add_test(pSuite, "negative", test_reverse_negative);

    pSuite = CU_add_suite("Task 2: Partition", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_add_test(pSuite, "empty", test_partition_empty);
    CU_add_test(pSuite, "all less", test_partition_all_less);
    CU_add_test(pSuite, "all greater", test_partition_all_greater);
    CU_add_test(pSuite, "example x=5", test_partition_example);
    CU_add_test(pSuite, "negative", test_partition_negative);
    CU_add_test(pSuite, "one less", test_partition_one_less);
    CU_add_test(pSuite, "one greater", test_partition_one_greater);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    CU_cleanup_registry();

    return CU_get_error();
}