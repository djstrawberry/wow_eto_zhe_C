#include <stdio.h>
#include "data.h"
#include "list_processing.h"

int main(void)
{
    result_t exit_code;

    node_t *A = NULL;
    node_t *B = NULL;
    node_t *C = NULL;
    size_t size;

    exit_code = initialize_tower(&A, &size);

    if (exit_code == OK_CODE)
        exit_code = hanoi(size, &A, &C, &B, 'A', 'C', 'B');

    return exit_code;
}