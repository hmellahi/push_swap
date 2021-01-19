
#include "minishell.h"


/*
// Linked list functions cusomized for tokens 
*/

t_tokens_node  *new_token_node(t_token **token)
{
    t_tokens_node *node;

    //node = malloc(sizeof(node));
    MALLOC(node);
    if (!node)
        return (NULL);
    node->token = *token;
    node->next = NULL;
    return (node);
}

void    push_back_token(t_tokens_node **list, t_token  **token)
{
    t_tokens_node      *iter;

    iter = *list;
    while (iter)
        iter = iter->next;
    iter = new_token_node(token);
    if (!iter)
        return ;
}


void    push_front_token(t_tokens_node **list, t_token **token)
{
    t_tokens_node      *new;

    if (NOT *list)
        *list = new_token_node(token);
    else
    {
        new = new_token_node(token);
        if (NOT new)
            return ;
        new->next = *list;
        *list = new;
    }
}
