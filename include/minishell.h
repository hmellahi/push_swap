
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../dbg/my_dbg.h"

typedef char            t_bool;

typedef struct          s_node
{
    void                *data;
    struct s_node       *next;
}                       t_node;

typedef struct          s_btree
{
    void                *data;
    struct s_btree      *r;
    struct s_btree      *l;
}                       t_btree;

typedef struct          s_file
{
    int                 fd;
    char                *name;
}                       t_file;

typedef struct          s_token
{
    char                *tok;
    char                *type;
    size_t              *len;
    int                 *order;
}                       t_token;

typedef struct          s_input
{
    char                *line;
    size_t              len;
    size_t              i;
}                       t_input;

//This holds everything. Well.. almost.
typedef struct          s_env
{
    int                 argc;
    char                **argv;
    char                **env_var;
    t_input             *input;
    t_node              *tokens;

    
}                       t_env;


# include "macros.h"
# include "functions.h"
# include "../dbg/my_dbg.h"

#endif
