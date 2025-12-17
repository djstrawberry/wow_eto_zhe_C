#include "list_processing.h"

result_t create_node(node_t **new_node, size_t diameter)
{
    result_t exit_code = OK_CODE;

    if (!new_node)
        exit_code = INVALID_PTR_CODE;
    else
    {
        *new_node = malloc(sizeof(node_t));
        if (!(*new_node))
            exit_code = MEMORY_ERR_CODE;
        else
        {
            (*new_node)->diameter = diameter;
            (*new_node)->next = NULL;
        }
    }

    return exit_code;
}

result_t push_front(node_t **tower, node_t *new_node)
{
    result_t exit_code = OK_CODE;

    if (!tower)
        exit_code = INVALID_PTR_CODE;
    else
    {
        new_node->next = *tower;
        *tower = new_node;
    }

    return exit_code;
}

result_t pop_front(node_t **tower, node_t **popped_node)
{
    result_t exit_code = OK_CODE;

    if (!tower)
        exit_code = INVALID_PTR_CODE;
    else
    {
        *popped_node = *tower;
        *tower = (*tower)->next;
    }

    return exit_code;
}

void free_list(node_t *tower)
{
    node_t *temp_node;
    while (tower)
    {
        temp_node = tower->next;
        free(tower);
        tower = temp_node;
    }
}