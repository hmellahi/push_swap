#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>


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



#endif