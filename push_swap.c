#include "checker.h"
void repeat_n_times(int (*func)(), t_stack *a, int n)
{
    while (n--)
        func(a);
}

void move_to_top(t_stack *a,int index)
{
    int moves;

    moves = index;
    if (moves > 0)
        repeat_n_times(rotate, a, moves);
    else
        repeat_n_times(rev_rotate, a, -moves);
}

int main(int ac, char **av)
{
    int i;
    int j;
    int x;
    long *k;
    t_stack *list_a;
    t_stack *list_b;

    list_a = newStack('a');
    list_b = newStack('b');
    i = 0;
    ac--;
    if (ac == 0)
        return (ft_exit(ERROR));
    while (++i <= ac)
    {
        j = -1;
        while (++j < strlen(av[i]))
        {
            x = av[i][j];
            if (!is_digit(x))
                return (ft_exit(ERROR));
        }
        k = malloc(sizeof(long));
        *k = ft_atoi(av[i]);
        //printf("%ld\n", *k);
        if (!is_unique(list_a, k))
            return (ft_exit(ERROR));
        push(list_a, k);
    }
    int chunk_index = 0;
    int half = list_a->size / 2;
    int chunk_size = list_a->size / 20;
    int index,min1,min2, hold_first, hold_sec;
    int hold_first_index = 9999;
    int hold_sec_index = 9999;
    t_stack *sorted_list = cpy(list_a);
    bubbleSort(&sorted_list->head);
    if (is_equal(sorted_list, list_a) == TRUE)
        return (ft_exit(COMPLETED));
    while (!is_empty(list_a))
    {
        int max_of_cc = void_to_num(get(sorted_list, chunk_index * chunk_size)->data);
        half = list_a->size / 2;
        i = -1;
        while (++i < list_a->size)
        {
            x = void_to_num(get(list_a, i)->data);
            if (x <= max_of_cc)
            {
                hold_first_index = i;
                hold_first = x;
                break;
            }
        }
        i = list_a->size;
        while (--i > hold_first_index)
        {
            x = void_to_num(get(list_a, i)->data);
            if (x <= max_of_cc)
            {
                hold_sec_index = i;
                hold_sec = x;
                break;
            }
        }
        if (hold_first_index != 9999)
        {
            if (hold_first_index >= half)
                min1 = hold_first_index - list_a->size;
            else
                min1 = hold_first_index;
        }
        if (hold_sec_index != 9999)
        {
            if (hold_sec_index >= half)
                min2 = hold_sec_index - list_a->size;
            else
                min2 = hold_sec_index;
        }
        index = abs(min1) > abs(min2) ? min2 : min1;
        move_to_top(list_a, index);
        if (!is_empty(list_a) && is_equal(sorted_list, list_a) == TRUE)
            return (ft_exit(COMPLETED));
        push_in_b(list_a, list_b);
        chunk_index++;
    }
    int max;
    t_node *curr;
    int moves;
    curr = list_b->head;
    while (!is_empty(list_b))
    {
        i = 0;
        max = void_to_num(get(sorted_list, sorted_list->size - i)->data);
        while (1)
        {
            if (void_to_num(curr->data) == max)
            {
                if (i >= list_b->size / 2)
                    moves = list_b->size - i;
                else
                    moves = i;
                move_to_top(list_b, moves);
                push_in_a(list_a, list_b);
                break;
            }
            curr = curr->next;
            i++;
            if (curr == list_b->head)
                break;
        }
    }
}