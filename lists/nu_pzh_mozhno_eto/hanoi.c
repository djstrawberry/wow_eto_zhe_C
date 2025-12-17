#include "hanoi.h"

size_t step_counter = 0;

result_t initialize_tower(node_t **tower, size_t *size)
{
    result_t exit_code = OK_CODE;
    node_t *new_node = NULL;

    exit_code = input_size(size);

    for (size_t i = *size; (exit_code == OK_CODE) && (i > 0); i--)
    {
        exit_code = create_node(new_node, i);
        if (exit_code == OK_CODE)
            exit_code = push_front(tower, new_node);
    }

    return exit_code;
}

static result_t move_disk(node_t **from, node_t **to, char from_name, char to_name)
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
        step_counter++;

    return exit_code;
}

result_t hanoi(size_t size, node_t **from, node_t **to, node_t **aux, char from_name, char to_name, char aux_name)
{
    result_t exit_code = OK_CODE;

    if (!from || !to || !aux)
        exit_code = INVALID_PTR_CODE;
    else if (size == 1)
        exit_code = move_disk(from, to, from_name, to_name);
    else
    {
        exit_code = hanoi(size - 1, from, aux, to, from_name, aux_name, to_name);

        if (exit_code == OK_CODE)
            exit_code = move_disk(from, to, from_name, to_name);

        if (exit_code == OK_CODE)
            exit_code = hanoi(size - 1, aux, to, from, aux_name, to_name, from_name);
    }

    return exit_code;
}