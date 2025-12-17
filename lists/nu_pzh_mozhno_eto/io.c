#include "io.h"

result_t input_size(size_t *size)
{
    result_t exit_code = OK_CODE;
    int temp_size;

    if (scanf("%d", &temp_size) != 1 || temp_size < 1)
        exit_code = INPUT_ERR_CODE;
    else
        *size = temp_size;

    return exit_code;
}