
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
    
}                       t_file;

//This holds everything. Well.. almost.

typedef struct          s_env
{
    
}                       t_env;

# include "macros.h"
# include "functions.h"
# include "../dbg/my_dbg.h"

#endif
