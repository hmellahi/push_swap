/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:35:22 by hmellahi          #+#    #+#             */
/*   Updated: 2021/04/26 03:40:52 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int    push_in_a(t_stack *a, t_stack *b)
{
    int *top;

    if (b->size == 0)
        return (FALSE);
    *top = pop(b);
    push(a, top);
    b->size--;
    //push(a->actions, "pa");
    return (TRUE);
}

int    push_in_b(t_stack *a, t_stack *b)
{
    int *top;

    if (a->size == 0)
        return (FALSE);
    *top = pop(a);
    push(b, top);
    a->size--;
    //push(b->actions, "pb");
    return (TRUE);
}