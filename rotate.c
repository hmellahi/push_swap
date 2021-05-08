/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmellahi <hmellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:39:42 by hmellahi          #+#    #+#             */
/*   Updated: 2021/05/05 16:02:57 by hmellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rotate(t_stack *stack)
{
	if (stack->size < 2)
		return (FALSE);
	RightshiftList((t_node **)&stack->head);
	if (CHECKER)
		return (TRUE);
	ft_putstr("r");
	ft_putchar(stack->name);
	ft_putstr("\n");
	return (TRUE);
}

int	rotate_a(t_stack *fs, t_stack *ss)
{
	return (rotate(fs));
}

int	rotate_b(t_stack *fs, t_stack *ss)
{
	return (rotate(ss));
}

int	rotate_both(t_stack *fs, t_stack *ss)
{
	rotate(fs);
	rotate(ss);
	return (TRUE);
}
