

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

void    print_tokens(t_tokens_node **tokens)
{
    t_tokens_node *iter;

    nl sp
    iter = *tokens;

    while (iter)
    {
        yo;
        print (iter->token->tok);
        iter = iter->next;
    }
    sp
}