#ifndef LIST_PROCESSING_H
#define LIST_PROCESSING_H

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

typedef struct node node_t;
struct node
{
    int number;
    node_t *next;
};

result_t create_node(node_t **node, int number);
result_t insert_end(node_t **head, node_t *new_node);
result_t delete_even(node_t **head);
void print_list(node_t *head);
void free_list(node_t *head);

#endif