#include <stdio.h>
#include <stdlib.h>
#include "listutils.h"

struct List *insert_back(struct List *node, int item)
{
   struct List *newnode = (struct List *) malloc(sizeof(struct List));
   if (newnode == NULL) return NULL;
   newnode->item = item;
   newnode->next = NULL;
   if (node) {
       while (node->next)
           node = node->next;
       node->next = newnode;
   }
   return newnode;
}

struct List *reverse_list(struct List *head)
{
    struct List *prev = NULL;
    struct List *curr = head;
    struct List *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

struct List *partition_list(struct List *head, int x)
{
    struct List *less_head = NULL;
    struct List *less_tail = NULL;
    struct List *greater_head = NULL;
    struct List *greater_tail = NULL;
    struct List *curr = head;

    while (curr != NULL) {
        struct List *next = curr->next;
        curr->next = NULL;

        if (curr->item < x) {
            if (less_head == NULL) {
                less_head = curr;
                less_tail = curr;
            } else {
                less_tail->next = curr;
                less_tail = curr;
            }
        } else {
            if (greater_head == NULL) {
                greater_head = curr;
                greater_tail = curr;
            } else {
                greater_tail->next = curr;
                greater_tail = curr;
            }
        }

        curr = next;
    }

    if (less_head == NULL) {
        return greater_head;
    }

    less_tail->next = greater_head;
    return less_head;
}

void print_list(struct List *node)
{
    while (node != NULL) {
        printf("%d", node->item);
        if (node->next != NULL) {
            printf(" -> ");
        }
        node = node->next;
    }
    printf(" -> NULL\n");
}

void free_list(struct List *head)
{
    struct List *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}