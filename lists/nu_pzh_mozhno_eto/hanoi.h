#ifndef HANOI_H
#define HANOI_H

#include "data.h"
#include "list_processing.h"
#include "io.h"

extern size_t step_counter;
extern node_t *A;
extern node_t *B;
extern node_t *C;

result_t initialize_tower(node_t **tower, size_t *size);
result_t hanoi(size_t size, node_t **from, node_t **to, node_t **aux);

#endif