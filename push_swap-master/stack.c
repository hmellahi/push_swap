#include "checker.h"

t_stack* newStack()
{
    t_stack *pt;

    pt = (t_stack*)malloc(sizeof(t_stack));
    pt->size = 0;
    pt->head = NULL;
    pt->type = "int";
    return (pt);
}

void        push(t_stack* pt, void *x)
{
    insertLast((t_node**)&pt->head, x);
    pt->size++;
}

int         peek(t_stack* pt)
{
    t_node *fs_node;

    fs_node = (t_node *)pt->head;
    return (void_to_num(fs_node));
}

int        pop(t_stack *pt)
{
    int first_num;

    if (pt->size == 0)
        return (-1);
    first_num = peek(pt);
    deleteFirst((t_node **)&pt->head);
    return (first_num);
}

void    display(t_stack *pt)
{
    if (pt->size == 0)
        return ;
    display_list((t_node*)pt->head, pt->type);
}

int    is_sorted(t_stack *pt)
{
    int i;
    int last;
    t_node *curr;
    t_node *head;

    i = -1;
    last = -1;
    head = (t_node*)pt->head;
    curr = head;
    while (1)
    {
        if (*((int*)curr->data) > last)
            return (FALSE);
        curr = curr->next;
        if (curr == head)
            break;
    }
    return (TRUE);
}

int is_empty(t_stack *pt)
{
    return (pt->size == 0);
}