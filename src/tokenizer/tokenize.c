
#include "minishell.h"

char *get_quoted_token(char *input, int *i)
{
    char    *token;

    if (input[0] == SINGLE_QT)
        token = tokenize_single_quoted(input, i);
    else
        token = tokenize_double_quoted(input, i);
    return (token);
}

char *tokenize_single_quoted(char *input, int *i)
{
    char    *token;

    return token;
}

char *tokenize_double_quoted(char *input, int *i)
{
    char    *token;
    char    c;
    char    pre;
    int     k;
    t_bool  done;

    k = 0;
    done = FALSE;
    while (input[k] && input[k] != ' ')
    {
        if (k == 0 && ++k)
            continue;
        c = input[k];
        pre = input[k - 1];
        
        //TODO:
        //-check if same
        
        if (c == DOUBLE_QT && pre != BACK_SLASH && (done = TRUE))
            break ;
        else if (c == DOUBLE_QT && pre == BACK_SLASH && ++k)
            continue ;
        k++;
    }
    if (done)
    {
        if (k - *i == 0)
        {
            print("DUP");
            token = str_dup("");
        }
        else
            token = sub_str(input, *i + 1, k - 1);
    }
    *i = k;
    return token;
}

char *get_token(ENV, char *input, int *i)
{
    char    *token;
    int     start, end;
    int     k;

    start = *i;
    k = 0;
    while (input[k] && input[k] != ' ')
        k++;
    if (k - start > 0)
        token = sub_str(input, start, k);
    else
        token = str_dup("");
    *i += k;
    return token;
}

int tokenize(char *input, ENV)
{
    int     i;
    int     len;
    int     k;
    char    c;
    char    *token;
    t_node  *tokens;
    
    //TODO:
    // Create new token on each different type

    //Check if str is "quoted"!

    
    // check_quoted_str
    // is_bad_quoted

    len = str_len(input);
    int start = 0;
    int end = 0;
    
    i = 0;
    while (i < len)
    {
        c = input[i];
        if (input[i] != SPACE)
        {
            if (c == DOUBLE_QT || c == SINGLE_QT)
                token = get_quoted_token(&input[i], &i);
            else
                token = get_token(env, &input[i], &i);
            if (token)
                print(token);
            else
                print("NULL");
            //push_back(&tokens, token);
        }
        else
            i++;
    }
    return 0;
}