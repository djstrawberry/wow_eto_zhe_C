#include <stdio.h>
#include "data.h"
#include "list_processing.h"
#include "file_processing.h"

int main(void)
{
    result_t exit_code = OK_CODE;

    node_t *head = NULL;

    exit_code = read_numbers(&head);

    if (exit_code == OK_CODE)
        exit_code = delete_even(&head);

    if (exit_code == OK_CODE)
        print_list(head);

    free_list(head);

    return exit_code;
}