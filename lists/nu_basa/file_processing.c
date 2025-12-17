#include "file_processing.h"

result_t read_numbers(node_t **head)
{
    result_t exit_code = OK_CODE;
    FILE *f = NULL;
    int number;
    node_t *new_node = NULL;

    if (!head)
        exit_code = INVLAID_PTR_CODE;

    if (exit_code == OK_CODE)
    {
        f = fopen("input.txt", "r");
        if (!f)
            exit_code = FILE_OPEN_ERR_CODE;
    }

    if (exit_code == OK_CODE)
    {
        while ((exit_code == OK_CODE) && (fscanf(f, "%d", &number) == 1))
        {
            exit_code = create_node(&new_node, number);
            if (exit_code == OK_CODE)
                exit_code = insert_end(head, new_node);
            if (exit_code != OK_CODE)
                free(new_node);
        }
    }

    if ((exit_code == OK_CODE) && (!feof(f)))
        exit_code = FILE_READ_ERR_CODE;

    if (f)
        fclose(f);

    return exit_code;
}