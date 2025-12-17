#include "io.h"

result_t input_size(size_t *size)
{
    result_t exit_code = OK_CODE;
    int temp_size;

    printf("Введите размер до 10 <3: ");

    if (scanf("%d", &temp_size) != 1 || temp_size < 1 || temp_size > 10)
        exit_code = INPUT_ERR_CODE;
    else
        *size = temp_size;

    return exit_code;
}

static void print_tower(node_t *tower)
{
    while (tower)
    {
        printf("%zu ", tower->diameter);
        tower = tower->next;
    }
    printf("\n");
}

void print_towers(void)
{
    printf("A: ");
    print_tower(A);
    printf("B: ");
    print_tower(B);
    printf("C: ");
    print_tower(C);
    printf("------------\n");
}