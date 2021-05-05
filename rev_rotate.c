/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 06:29:53 by hamza             #+#    #+#             */
/*   Updated: 2021/05/04 06:30:26 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int    rev_rotate(t_stack *stack)
{
    if (stack->size < 2)
        return (FALSE);
    LeftshiftList((t_node **)&stack->head);
    if (CHECKER)
        return (TRUE);
    ft_putstr("rr");
    ft_putchar(stack->name);
    ft_putstr("\n");
    return (TRUE);
}

int    rev_rotate_a(t_stack *fs, t_stack *ss)
{
    rev_rotate(fs);
    return (TRUE);
}

int    rev_rotate_b(t_stack *fs, t_stack *ss)
{
    rev_rotate(ss);
    return (TRUE);
}

int    rev_rotate_both(t_stack *fs, t_stack *ss)
{
    rev_rotate(fs);
    rev_rotate(ss);
    return (TRUE);
}
