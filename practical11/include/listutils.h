#ifndef LISTUTILS_H
#define LISTUTILS_H

struct List {
    int item;
    struct List *next;
};

struct List *insert_back(struct List *node, int item);
struct List *reverse_list(struct List *head);
struct List *partition_list(struct List *head, int x);
void print_list(struct List *node);
void free_list(struct List *head);

#endif