
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

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

//This holds everything. Well.. almost.
typedef struct          s_env
{
    int                 argc;
    char                **argv;
    char                **env_var;
    t_node              *tokens;

    
}                       t_env;

typedef struct          s_token
{
    char                *token;
    char                *type;
    char                *len;
    char                *order;
}                       t_token;

# include "macros.h"
# include "functions.h"
# include "../dbg/my_dbg.h"

#endif
