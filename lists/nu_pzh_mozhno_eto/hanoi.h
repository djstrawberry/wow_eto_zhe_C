#ifndef HANOI_H
#define HANOI_H

#include "data.h"
#include "list_processing.h"

extern step_counter;

result_t initialize_tower(node_t **tower, size_t *size);
result_t hanoi(node_t **from, node_t **to, node_t **aux, char from_name, char to_name, char aux_name);

#endif