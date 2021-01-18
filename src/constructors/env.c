
#include "minishell.h"

//initialize props
t_env   *init_env(int argc, char **argv, char **env_var)
{
    t_env   *env;

    MALLOC(env);
    MALLOC(env->input);

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