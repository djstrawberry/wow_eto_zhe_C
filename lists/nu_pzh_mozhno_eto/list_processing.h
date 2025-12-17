#ifndef LIST_PROCESSING_H
#define LIST_PROCESSING_H

#include <stdlib.h>
#include "data.h"

typedef struct node node_t;
struct node
{
    size_t diameter;
    node_t *next;
};

result_t create_node(node_t **new_node, size_t diameter);
result_t push_front(node_t **tower, node_t *new_node);
result_t pop_front(node_t **tower, node_t **popped_node);
void free_list(node_t *tower);

#endif