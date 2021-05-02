/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmellahi <hmellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:35:22 by hmellahi          #+#    #+#             */
/*   Updated: 2021/05/02 16:58:46 by hmellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int    push_in_a(t_stack *a, t_stack *b)
{
    int *top;

    if (b->size == 0)
        return (FALSE);
    top = malloc(4);
    *top = pop(b);
    push2(a, top);
    b->size--;
    if (CHECKER)
        return (TRUE);
    ft_putstr("pa\n");
    return (TRUE);
}

int    push_in_b(t_stack *a, t_stack *b)
{
    int *top;

    if (a->size == 0)
        return (FALSE);
    top = malloc(4);
    *top = pop(a);
    push2(b, top);
    a->size--;
    if (CHECKER)
        return (TRUE);
    ft_putstr("pb\n");
    return (TRUE);
}