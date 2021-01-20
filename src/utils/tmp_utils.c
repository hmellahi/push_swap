
#include "../../include/minishell.h"


void    print_array(t_array *arr, t_bool minus)
{
    if (minus)
        for (size_t i = 0; i < arr->size && arr->arr[i] != -1; i++)
            DN(arr->arr[i]);
    else
        for (size_t i = 0; i < arr->size; i++)
            DN(arr->arr[i]);
}

void    print_tokens(t_node **tokens)
{
    t_node *iter;

    iter = *tokens;
    while (iter)
    {
        if (iter->data == NULL)
        {
            print("<NULL>");
            break;
        }
        t_token *token = iter->data;

        if (token)
            printf("@> [%s]\n", (char*)(token->tok));
        else
            printf("$$$$$$$$$$$$$\n");
        iter = iter->next;
    }
    sp
}