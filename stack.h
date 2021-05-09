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
void        push2(t_stack *pt, void *x);
int         sort_three_nums(t_stack *list_a);
int         sort_five_nums(t_stack *sorted_list, t_stack *list_a, t_stack *list_b);
void        repeat_n_times(int (*func)(), t_stack *a, int n);
void        move_to_top(t_stack *a,int index);
void        moves_back_to_a(t_stack *list_a, t_stack *list_b, t_stack *sorted_list);
void        free_stack(t_stack **list);
t_string	*init_insts(void);
#endif