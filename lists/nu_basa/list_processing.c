#include "list_processing.h"

result_t create_node(node_t **node, int number)
{
    result_t exit_code = OK_CODE;

    if (!node)
        exit_code = INVLAID_PTR_CODE;
    else
    {
        *node = malloc(sizeof(node_t));
        if (!(*node))
            exit_code = MEMORY_ERR_CODE;
        else
        {
            (*node)->number = number;
            (*node)->next = NULL;
        }
    }

    return exit_code;
}

result_t insert_end(node_t **head, node_t *new_node)
{
    result_t exit_code = OK_CODE;
    node_t *current_node = *head;

    if (!head)
        exit_code = INVLAID_PTR_CODE;
    else if (!(*head))
        *head = new_node;
    else
    {
        while (current_node->next)
            current_node = current_node->next;
        
        current_node->next = new_node;
    }

    return exit_code;
}

result_t delete_even(node_t **head)
{
    result_t exit_code = OK_CODE;

    if (!head)
        exit_code = INVLAID_PTR_CODE;
    else if (*head)
    {
        node_t *current_node = *head;
        node_t *prev_node = NULL;
        node_t *temp_node = NULL;
        while (current_node)
        {
            temp_node = current_node->next;
            if (current_node->number % 2 == 0)
            {
                if (!prev_node)
                    *head = current_node->next;
                else
                    prev_node->next = current_node->next;
                free(current_node);
            }
            else
                prev_node = current_node;
            current_node = temp_node;
        }
    }

    return exit_code;
}

void print_list(node_t *head)
{
    if (!head)
        printf("Хуй пиписа!\n");
    while (head)
    {
        printf("%d ", head->number);
        head = head->next;
    }
}

void free_list(node_t *head)
{
    node_t *temp_node = NULL;

    while (head)
    {
        temp_node = head;
        head = head->next;
        free(temp_node);
    }
}