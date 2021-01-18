
#include "minishell.h"

t_token    *tokenize_quoted_input(ENV)
{
    t_token    *token;

    if (env->input->line[env->input->i] == SINGLE_QT)
        token = tokenize_single_quoted(env);
    else
        token = tokenize_double_quoted(env);
    return (token);
}

t_token    *tokenize_single_quoted(ENV)
{
    t_token     *token;
    size_t      j;
    char        *line;

    line = env->input->line;
    j = env->input->i + 1;
    while (j < env->input->len)
    {
        if (line[j] == DOUBLE_QT && line[j - 1] != BACK_SLASH)
        {
            j++;
            break;
        }
        j++;
    }
    token = new_token(sub_str(line, env->input->i, j));
    env->input->i = j;
    return (token);
}

t_token    *tokenize_double_quoted(ENV)
{
    t_token     *token;
    size_t      j;
    char        *line;

    line = env->input->line;
    j = env->input->i + 1;
    while (j < env->input->len)
    {
        if (line[j] == DOUBLE_QT && line[j - 1] != BACK_SLASH)
        {
            j++;
            break;
        }
        j++;
    }
    token = new_token(sub_str(line, env->input->i, j));
    env->input->i = j;
    return (token);
    //should be cleaned from backSlashes
}

t_token *get_token(ENV)
{
    t_token *token;
    size_t  j;
    char    *line;

    line = env->input->line;
    j = env->input->i + 1;
    while (j < env->input->len)
    {
        //[ cd d\ ir]
        if (line[j] == ' ' && line[j - 1] != BACK_SLASH)
        {
            //j++;
            break ;
        }
        j++;
    }
    token = new_token(sub_str(line, env->input->i, j));
    env->input->i = j;
    return token;
}

int tokenize_input(ENV)
{
    t_token *token;
    char    *line;
    int     i;
    int     j;

    //TODO:
    // -Create new token on each new piece of info
    // -Check if token is "quoted" && if is_bad_quoted
    // -Clean quoted token (skipping special chars)

    line = env->input->line;
    env->input->len = str_len(line);
    i = 0;
    while (i < env->input->len)
    {
        if (line[i] != SPACE)
        {
            env->input->i = i;
            if (line[i] == DOUBLE_QT || line[i] == SINGLE_QT)
                token = tokenize_quoted_input(env);
            else
                token = get_token(env);
            i = env->input->i; //Updating index
            print(token->tok);
            push_back(&env->tokens, token);
        }
        else
            i++;
    }
    return 0;
}