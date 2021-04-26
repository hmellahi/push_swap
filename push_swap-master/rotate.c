/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:39:42 by hmellahi          #+#    #+#             */
/*   Updated: 2021/04/26 03:43:00 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int    rotate(t_stack *stack)
{
    if (stack->size < 2)
        return (FALSE);
    RightshiftList((t_node **)&stack->head);
    return (TRUE);
}

int    rev_rotate(t_stack *stack)
{
    if (stack->size < 2)
        return (FALSE);
    LeftshiftList((t_node **)&stack->head);
    return (TRUE);
}

int    rotate_a(t_stack *fs, t_stack *ss)
{
    //push(fs->actions, "ra");
    return (rotate(fs));
}

int    rotate_b(t_stack *fs, t_stack *ss)
{
    //push(ss->actions, "rb");
    return (rotate(ss));
}

int    rotate_both(t_stack *fs, t_stack *ss)
{
    rotate(fs);
    rotate(ss);
    return (TRUE);
}

int    rev_rotate_a(t_stack *fs, t_stack *ss)
{
   // push(fs->actions, "rra");
    rev_rotate(fs);
    return (TRUE);
}

int    rev_rotate_b(t_stack *fs, t_stack *ss)
{
    //push(ss->actions, "rrb");
    rev_rotate(ss);
    return (TRUE);
}

int    rev_rotate_both(t_stack *fs, t_stack *ss)
{
    rev_rotate(fs);
    rev_rotate(ss);
    return (TRUE);
}