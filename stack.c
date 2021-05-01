#include "checker.h"

t_stack *newStack(char name)
{
    t_stack *pt;

    pt = (t_stack *)malloc(sizeof(t_stack));
    pt->size = 0;
    pt->head = NULL;
    pt->type = INT;
    pt->name = name;
    return (pt);
}

void    free_stack(t_stack *pt)
{
    freeList(&pt->head);
    free(pt);
}

t_stack *cpy(t_stack *old)
{
    t_stack *new;
    t_node *curr;

    new = newStack(old->name);
    curr = old->head;
    while(1)
    {
        push(new, curr->data);
        curr = curr->next;
        if (curr == old->head)
            break;
    }
    return (new);
}

int     is_equal(t_stack *a, t_stack *b)
{
    t_node *curr2;
    t_node  *curr;

    curr = a->head;
    curr2 = b->head;
    while(1)
    {
        if (void_to_num(curr->data) != void_to_num(curr2->data))
            return (FALSE);
        curr = curr->next;
        curr2 = curr2->next;
        if (curr == a->head || curr2 == b->head)
            break;
    }
    return (void_to_num(curr->data) == void_to_num(curr2->data) ? TRUE : FALSE);
}

void push(t_stack *pt, void *x)
{
    insertLast(&pt->head, x);
    pt->size++;
}

int peek(t_stack *pt)
{
    t_node *fs_node;

    fs_node = pt->head;
    return (void_to_num(fs_node->data));
}

int pop(t_stack *pt)
{
    int first_num;

    if (pt->size == 0)
        return (-1);
    first_num = peek(pt);
    deleteFirst(&pt->head);
    return (first_num);
}

void display(t_stack *pt)
{
    if (pt->size == 0)
        return;
    display_list(pt->head, pt->type);
}

int is_sorted(t_stack *pt)
{
    int i;
    int min;
    t_node *curr;
    t_node *head;

    i = -1;
    min = -1;
    head = (t_node *)pt->head;
    curr = head;
    while (1)
    {
        if (void_to_num(curr->data) < min)
            return (FALSE);
        min = void_to_num(curr->data);
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