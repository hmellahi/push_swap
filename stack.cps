 // Utility function to initialize the stack
#include "checker.h"

t_stack* newStack(int capacity)
{
    t_stack *pt;

    pt = (t_stack*)malloc(sizeof(t_stack));
    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);
    return (pt);
}
 
// Utility function to return the size of the stack
int size(t_stack *pt) {
    return (pt->top);
}
 
// Utility function to check if the stack is empty or not
int is_empty(t_stack *pt) {
    return (pt->top == -1);                   // or return size(pt) == 0;
}
 
// Utility function to check if the stack is full or not
int is_full(t_stack *pt) {
    return (pt->top == pt->maxsize - 1);      // or return size(pt) == pt->maxsize;
}

t_stack    *scaleit_then_throw_old_in_trash(t_stack *pt)
{
    t_stack *new;
    int     i;

    i = -1;
    new = (t_stack*)malloc(sizeof(t_stack));
    new->items = (int*)malloc(sizeof(int) * (pt->maxsize * 2));
    new->maxsize = pt->maxsize * 2;
    new->top = ++pt->top;
    while (++i < size(pt))
        new->items[i] = pt->items[i];
    puts("\n");
    free(pt->items);
    return (new);
}
// Utility function to add an element `x` to the stack
void push(t_stack *pt, int x)
{
    // check if the stack is already full. Then inserting an element would
    // lead to stack overflow
    if (is_full(pt))
    {
        puts("fulllll ;_0");
        pt = scaleit_then_throw_old_in_trash(pt);
    }
    // add an element and increment the top's index
    pt->items[++pt->top] = x;
}
 
// Utility function to return the top element of the stack
int peek(t_stack *pt)
{
    // check for an empty stack
    if (!is_empty(pt)) {
        return (pt->items[0]);
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 
// Utility function to pop a top element from the stack
int pop(t_stack *pt)
{
    int i;
    int last;
    // check for stack underflow
    if (is_empty(pt))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
    last = peek(pt);
    printf("Removing %d\n", last);
    i = -1;
    while (++i < pt->maxsize - 1)
        pt->items[i] = pt->items[i + 1];
    pt->top--;
    pt->maxsize--;
    // decrement stack size by 1 and (optionally) return the popped element
    return (last);
}

int    is_sorted(t_stack *pt)
{
    int i;
    int last;

    i = -1;
    last = -1;
    while (++i < size(pt))
    {
        if (pt->items[i] < last)
            return (FALSE);
        last = pt->items[i];
    }
    return (TRUE);
}