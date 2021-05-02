// Data structure to represent a stack
#ifndef STACK_H
#define STACK_H
#include "double_linked_list.h"


typedef struct  s_stack
{
    int     size;
    int     type;
    char    name;
    t_node  *head;
    t_node  *actions;
}               t_stack;

int         peek(t_stack *pt);
void        push(t_stack*pt, void* x);
void        display(t_stack *pt);
int         is_empty(t_stack*pt);
int         is_full(t_stack*pt);
int         pop(t_stack*pt);
t_stack     *newStack(char name);
int         is_sorted(t_stack*pt);
char        is_unique(t_stack *pt, void* data);
t_node      *get(t_stack *pt, int index);
t_stack     *cpy(t_stack *old);
int         is_equal(t_stack *a, t_stack *b);
void    free_stack(t_stack *pt);
void push2(t_stack *pt, void *x);
#endif