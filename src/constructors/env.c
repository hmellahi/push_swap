
#include "minishell.h"

//initialize props
t_env   *init_env(int argc, char **argv, char **env_var)
{
    t_env   *env;

    MALLOC(env);
    MALLOC(env->input);
    env->tokens = NULL;
    //env->tokens = malloc(sizeof(t_node));
    return (env);
}

t_token *new_token(void *tok)
{
    t_token *token;

    MALLOC(token);
    if (tok)
        token->tok = tok;
    return (token);
}

#define INT_ARR sizeof(int)
#define CHAR_ARR sizeof(char)
#define SHORT_ARR sizeof(short)

t_array *new_array(int size)
{
    t_array *array;
    int     i;

    MALLOC(array);
    ARRLLOC(array->arr, size);
    array->size = size;
    i = 0;
    while (i < size)
        array->arr[i++] = -1;
    return (array);
}