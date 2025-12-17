#include <stdio.h>
#include "data.h"
#include "list_processing.h"
#include "hanoi.h"

node_t *A = NULL;
node_t *B = NULL;
node_t *C = NULL;

int main(void)
{
    result_t exit_code;

    size_t size;

    exit_code = initialize_tower(&A, &size);

    if (exit_code == OK_CODE)
        print_towers();

    if (exit_code == OK_CODE)
        exit_code = hanoi(size, &A, &C, &B);

    if (exit_code == OK_CODE)
        printf("Кол-во перестановок: %zu\n", step_counter);

    free_list(A);
    free_list(B);
    free_list(C);

    return exit_code;
}