
# include "minishell.h"

int read_input(char **input)
{
	ssize_t read_ret;
    char    *buff;
    char    *p;

    ARRLLOC(buff, 2);
    *input = str_dup("");
    while ((read_ret = read(0, buff, 1)) != -1)
    {
        buff[read_ret] = 0;
        if (*buff == EOL)
            return 0;
        p = *input;
        *input = str_join(*input, buff);
        free(p);
    }
    if (read_ret == -1)
        return (-1);
    return (0);
}

int shell_prompt(ENV)
{
    int     ret; 
    char    *input;

/*
    TODO:
        +wait for input
        -tokenize input
        -run lexer
        -parse
        -execute
*/

    put_str(SHELL_NAME);
    put_str("$ ");

    if (read_input(&input) == -1)
        return (-1);
    else if (line_isempty(input))
    {
        //FLUSH;
        return (0);
    }
    //print(input);
    //ret = tokenize(input, env);
    //ret = lex_tokens();
    //ret = parse_tokens();
    //ret = execute();
    return (0);
}

int main(int argc, char **argv, char **env_vars)
{
    t_env   *env;
    char    *shell_ret;

    env = init_env();
    
    //env->argc = argc;
    //env->argv = argv;
    //env->env_vars = env_vars;
    int i = 0;
    while (1)
    {
        //printf("[%d]\n", i++);
        if (shell_prompt(env))
            break;
    }
    //Free allocated mem
    return (0);
}
