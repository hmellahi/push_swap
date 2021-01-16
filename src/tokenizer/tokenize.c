
#include "minishell.h"

char *get_tokens(char *input, env)
{
    int     i;
    int     k;
    char    *token;
    t_node  *tokens;
    
    //TODO:
    // Create new token on each different type

    //Check if str is "quoted"!

    int start = 0;
    int end = 0;
    i = 0;
    while (input[i])
    {
        if (input[i] != SPACE)
        {
            start = i;
            k = i;
            while (input[k] && input[k] != ' ')
                k++;
            token = sub_str(input, start, k);
            push_back(&tokens, token);
        }
    }
    

    return tokens;
}