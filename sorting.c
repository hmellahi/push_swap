/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 00:59:09 by hamza             #+#    #+#             */
/*   Updated: 2021/05/05 00:08:26 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void repeat_n_times(int (*func)(), t_stack *a, int n)
{
    while (n-- > 0)
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

int     sort_three_nums(t_stack *list_a)
{
    int index_of_max;
    int *max;
    t_stack *sorted_list;

    sorted_list = cpy(list_a);
    bubbleSort(&sorted_list->head);
    max = get(sorted_list, 2)->data;
    index_of_max = get_index_of(list_a->head, max);
    if (index_of_max == 0)
        rotate(list_a);
    else if (index_of_max == 1)
        rev_rotate(list_a);
    if (!is_equal(sorted_list, list_a))
        swap(list_a);
    return (0);
}

int    sort_five_nums(t_stack *sorted_list, t_stack *list_a, t_stack *list_b)
{
    int *x;
    int index;

    x = get(sorted_list, 0)->data;
    index = get_index_of(list_a->head, x);
    if (index > list_a->size / 2)
        index -= list_a->size;
    move_to_top(list_a, index);
    push_in_b(list_a, list_b);
    x = get(sorted_list, 1)->data;
    index = get_index_of(list_a->head, x);
    if (index > list_a->size / 2)
        index = index - list_a->size;
    move_to_top(list_a, index);
    push_in_b(list_a, list_b);
    sort_three_nums(list_a);
    if (is_sorted(list_b))
        swap(list_b);
    push_in_a(list_a, list_b);
    push_in_a(list_a, list_b);
    return (0);
}


void    moves_back_to_a(t_stack *list_a, t_stack *list_b, t_stack *sorted_list)
{
    int     *max;
    int     moves;
    int     i;
    int     index;

    i = 0;
    //display(list_b);
    while (!is_empty(list_b))
    {
        i++;
        max = get(sorted_list, sorted_list->size - i)->data;
        moves = get_index_of(list_b->head, max);
        if (moves >= list_b->size / 2)
            moves = moves -list_b->size;
        //printf("%d|%d\n", *max, moves);
        move_to_top(list_b, moves);
        push_in_a(list_a, list_b);
        //display(list_b);
        //display(list_a);
    }
}