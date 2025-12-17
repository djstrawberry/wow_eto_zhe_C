#include "hanoi.h"

size_t step_counter = 0;

result_t initialize_tower(node_t **tower, size_t *size)
{
    result_t exit_code = OK_CODE;

    exit_code = input_size(size);

    for (size_t i = 1; (exit_code == OK_CODE) && (i <= *size); i++)
    {
        node_t *new_node = NULL;
        exit_code = create_node(&new_node, i);
        if (exit_code == OK_CODE)
            exit_code = push_front(tower, new_node);
    }

    return exit_code;
}

static result_t move_disk(node_t **from, node_t **to)
{
    result_t exit_code = OK_CODE;
    node_t *disk = NULL;

    if (!from || !to)
        exit_code = INVALID_PTR_CODE;
    else
    {
        exit_code = pop_front(from, &disk);
        if (exit_code == OK_CODE)
            exit_code = push_front(to, disk);
    }

    if (exit_code == OK_CODE)
    {
        step_counter++;
        print_towers();
    }

    return exit_code;
}

result_t hanoi(size_t size, node_t **from, node_t **to, node_t **aux)
{
    result_t exit_code = OK_CODE;

    if (!from || !to || !aux)
        exit_code = INVALID_PTR_CODE;
    else if (size == 1)
        exit_code = move_disk(from, to);
    else
    {
        exit_code = hanoi(size - 1, from, aux, to);

        if (exit_code == OK_CODE)
            exit_code = move_disk(from, to);

        if (exit_code == OK_CODE)
            exit_code = hanoi(size - 1, aux, to, from);
    }

    return exit_code;
}