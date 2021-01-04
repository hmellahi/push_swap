
#include "minishell.h"

int read_input(char **input)
{
    int ret;

    ret = get_line(1, input);
    if (ret == -1)
        return (-1);
    return (0);
}

int shell_prompt(ENV)
{
    //This gets updated in each function call,
    // if an error occured, it gets a non-zero value.
    int     ret; 
    char    *input;

/*
    TODO:
        -wait for input
        -tokenize input
        -run  lexer
        -parse
        -execute
*/
    put_str(SHELL_NAME);
    put_str("$ ");

    //ret = 0;
    ret = read_input(&input);
    if (ret)
        return (ret);
    else if (line_isempty(&input))
        return (0);

    ret = tokenize(input, env);
    if (ret)
        return ret;
    //ret = lex_tokens();  //Assign each token to it's
    if (ret)
        return (ret);
    //ret = parse_tokens();
    if (ret)
        return (ret);
    //ret = execute();
    return (ret);
}

int main(int argc, char **argv, char **env)
{
    t_env   *env;

    env = init_env();
    while (1)
        if (shell_prompt(env))
            return -1;
    return (0);
}