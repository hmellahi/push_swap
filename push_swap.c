/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 06:45:29 by hamza             #+#    #+#             */
/*   Updated: 2021/05/05 02:24:43 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    get_first_index(t_stack *list_a, int max_of_cc, int *first_index)
{
    int i;
    int x;
    int half;

    *first_index = 9999;
    half = list_a->size / 2;
    i = -1;
    while (++i < list_a->size)
    {
        x = void_to_num(get(list_a, i)->data);
        if (x <= max_of_cc)
        {
            *first_index = i;
            break;
        }
    }
    if (*first_index >= half && *first_index != 9999)
        *first_index -= list_a->size;
}

void    get_sec_index(t_stack *list_a, int max_of_cc, int *sec_index, int first_index)
{
    int i;
    int x;
    int half;

    *sec_index = 9999;
    i = list_a->size;
    half = list_a->size / 2;
    while (--i > first_index)
    {
        x = void_to_num(get(list_a, i)->data);
        if (x <= max_of_cc)
        {
            *sec_index = i;
            break;
        }
    }
    if (*sec_index >= half && *sec_index != 9999)
        *sec_index -= list_a->size;
}

int     sort_n_nums(t_stack *sorted_list, t_stack *list_a, t_stack *list_b)
{
    int chunk_index;
    int chunk_size;
    int index;
    int first_index;
    int sec_index;
    int max_of_cc;
    int i;

    chunk_size = 2;
    if (list_a->size == 500)
        chunk_size = list_a->size / 40;
    else if (list_a->size >= 100)
        chunk_size = list_a->size / 10;
    chunk_index = 0;
    i = 0;
    while (!is_empty(list_a))
    {
        if (i % chunk_size == 0)
            chunk_index += chunk_size;
        max_of_cc = void_to_num(get(sorted_list, chunk_index - 1)->data);
        get_first_index(list_a, max_of_cc, &first_index);
        get_sec_index(list_a, max_of_cc, &sec_index, first_index);
        index = abs(first_index) > abs(sec_index) ? sec_index : first_index;
        //printf("%d|%d\n", max_of_cc, chunk_index);
        move_to_top(list_a, index);
        if (!is_empty(list_a) && is_equal(sorted_list, list_a) == TRUE)
            return (ft_exit(COMPLETED));
        push_in_b(list_a, list_b);
        i++;
    }
    //display(list_b);
    moves_back_to_a(list_a, list_b, sorted_list);
    //display(list_a);
    return (0);
}

int main(int ac, char **av)
{
    t_stack *list_a;
    t_stack *list_b;
    t_stack *sorted_list;

    list_a = newStack('a'); 
    list_b = newStack('b');
    if (ac == 0)
        return (ft_exit(ERROR));
    insert_nums(list_a, list_b, --ac, av);
    sorted_list = cpy(list_a);
    bubbleSort(&sorted_list->head);
    if (is_equal(sorted_list, list_a) == TRUE)
        return (ft_exit(COMPLETED));
    if (list_a->size == 3)
        return (sort_three_nums(list_a));
    else if (list_a->size == 5)
        return (sort_five_nums(sorted_list, list_a, list_b));
    else
        return (sort_n_nums(sorted_list, list_a, list_b));
    //  int chunk_index = 0;
    // int half = list_a->size / 2;
    // int chunk_size = 1;
    // int index,min1,min2, hold_first, hold_sec;
    // int hold_first_index;
    // int hold_sec_index;
    // sorted_list = cpy(list_a);
    // bubbleSort(&sorted_list->head);
    // if (is_equal(sorted_list, list_a) == TRUE)
    //     return (ft_exit(COMPLETED));
    // if (list_a->size == 3)
    //     sort_three_nums(list_a);
    // else if (list_a->size == 5)
    //     sort_five_nums(sorted_list, list_a, list_b);
    // int i,x;
    // while (!is_empty(list_a))
    // {
    //     hold_first_index = 9999;
    //     hold_sec_index = 9999;
    //     int max_of_cc = void_to_num(get(sorted_list, chunk_index * chunk_size)->data);
    //     half = list_a->size / 2;
    //     i = -1;
    //     while (++i < list_a->size)
    //     {
    //         x = void_to_num(get(list_a, i)->data);
    //         if (x <= max_of_cc)
    //         {
    //             hold_first_index = i;
    //             hold_first = x;
    //             break;
    //         }
    //     }
    //     i = list_a->size;
    //     while (--i > hold_first_index)
    //     {
    //         x = void_to_num(get(list_a, i)->data);
    //         if (x <= max_of_cc)
    //         {
    //             hold_sec_index = i;
    //             hold_sec = x;
    //             break;
    //         }
    //     }
    //     if (hold_first_index != 9999)
    //     {
    //         if (hold_first_index >= half)
    //             min1 = hold_first_index - list_a->size;
    //         else
    //             min1 = hold_first_index;
    //     }
    //     if (hold_sec_index != 9999)
    //     {
    //         if (hold_sec_index >= half)
    //             min2 = hold_sec_index - list_a->size;
    //         else
    //             min2 = hold_sec_index;
    //     }
    //     index = abs(min1) > abs(min2) ? min2 : min1;
    //     move_to_top(list_a, index);
    //     if (!is_empty(list_a) && is_equal(sorted_list, list_a) == TRUE)
    //         return (ft_exit(COMPLETED));
    //     push_in_b(list_a, list_b);
    //     chunk_index++;
    // }
    // //moves_back_to_a(list_a, list_b, sorted_list);
    // int max;
    // t_node *curr;
    // int moves;
    // curr = list_b->head;
    // while (!is_empty(list_b))
    // {
    //     i = 0;
    //     max = void_to_num(get(sorted_list, sorted_list->size - i)->data);
    //     while (1)
    //     {
    //         if (void_to_num(curr->data) == max)
    //         {
    //             if (i >= list_b->size / 2)
    //                 moves = list_b->size - i;
    //             else
    //                 moves = i;
    //             move_to_top(list_b, moves);
    //             push_in_a(list_a, list_b);
    //             break;
    //         }
    //         curr = curr->next;
    //         i++;
    //         if (curr == list_b->head)
    //             break;
    //     }
    // }
    // display(list_a);
}
