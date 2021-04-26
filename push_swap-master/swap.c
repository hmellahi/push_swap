/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:35:25 by hmellahi          #+#    #+#             */
/*   Updated: 2021/04/26 03:42:36 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int    swap(t_stack *list)
{
    int *cpy;
    t_node *head;

    head = (t_node*)list->head;
    if (list->size < 2)
        return (FALSE);
    cpy = head->data;
    head->data = head->next->data;
    head->next->data = cpy;
    return (TRUE);
}

int    swap_list_a(t_stack *list_a, t_stack *list_b)
{
    //push(list_a->actions, "sa");
    return (swap(list_a));
}

int    swap_list_b(t_stack *list_a, t_stack *list_b)
{
    //push(list_b->actions, "sb");
    return (swap(list_b));
}

int    swap_both(t_stack *list_a, t_stack *list_b)
{
    swap(list_a);
    swap(list_b);
    return (TRUE);
}