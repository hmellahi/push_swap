

#include "minishell.h"


void    print_array(t_array *arr, t_bool minus)
{
    if (minus)
        for (size_t i = 0; i < arr->size && arr->arr[i] != -1; i++)
            DN(arr->arr[i]);
    else
        for (size_t i = 0; i < arr->size; i++)
            DN(arr->arr[i]);
}