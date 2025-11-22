#include <stdio.h>
#include <stdlib.h>
#include "listutils.h"

int main()
{
    struct List *head = NULL;

    printf("===== TASK 1: REVERSE LINKED LIST =====\n\n");

    printf("Test: Reverse [1 -> 2 -> 3 -> 4 -> 5]\n");
    head = insert_back(head, 1);
    insert_back(head, 2);
    insert_back(head, 3);
    insert_back(head, 4);
    insert_back(head, 5);

    printf("Before: ");
    print_list(head);

    head = reverse_list(head);

    printf("After:  ");
    print_list(head);
    printf("\n");

    free_list(head);
    head = NULL;

    printf("===== TASK 2: PARTITION LINKED LIST =====\n\n");

    printf("Test: Partition [3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1] around x=5\n");
    head = insert_back(head, 3);
    insert_back(head, 5);
    insert_back(head, 8);
    insert_back(head, 5);
    insert_back(head, 10);
    insert_back(head, 2);
    insert_back(head, 1);

    printf("Before: ");
    print_list(head);

    head = partition_list(head, 5);

    printf("After:  ");
    print_list(head);

    free_list(head);

    return 0;
}