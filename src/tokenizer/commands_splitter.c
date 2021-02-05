
#include "minishell.h"

t_bool     split_commands(ENV)
{
    t_node      *iter;
    t_token     *token;
    t_cmd       *cmd;
    t_bool      flag;

    //Either this allocation, or tweaking new_node()
    MALLOC(env->commands);

    flag = FALSE;
    cmd = new_cmd();
    iter = env->tokens;
    while (iter)
    {
        token = iter->data;
        if (str_cmp(token->tok, ";")
            OR str_cmp(token->tok, "||"))
        {
            // print("ANOTHER ONE");
            push_back(&env->commands, cmd);
            // print("AFTER");
            cmd = new_cmd();
            flag = TRUE;
        }
        else if (str_cmp(token->tok, "&&"))
        {
            push_back(&env->commands, cmd);
            cmd = new_cmd();
            flag = TRUE;
        }
        else
        {
            push_back(&cmd->tokens, iter->data);
            flag = FALSE;
            // when there is no such SEP, add to commands list.
        }
        iter = iter->next;
    }
    return 0;
}
