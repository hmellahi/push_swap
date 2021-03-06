/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 06:31:55 by hamza             #+#    #+#             */
/*   Updated: 2021/05/09 00:45:01 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*newStack(char name)
{
	t_stack	*pt;

	pt = (t_stack *)malloc(sizeof(t_stack));
	pt->size = 0;
	pt->head = NULL;
	pt->type = INT;
	pt->name = name;
	return (pt);
}

t_stack	*cpy(t_stack *old)
{
	t_stack	*new;
	t_node	*curr;
	int		*data;

	new = newStack(old->name);
	curr = old->head;
	while (1)
	{
		data = malloc(sizeof(int));
		*data = void_to_num(curr->data);
		push(new, data);
		curr = curr->next;
		if (curr == old->head)
			break ;
	}
	return (new);
}

int	is_equal(t_stack *a, t_stack *b)
{
	t_node	*curr2;
	t_node	*curr;

	curr = a->head;
	curr2 = b->head;
	while (1)
	{
		if (void_to_num(curr->data) != void_to_num(curr2->data))
			return (FALSE);
		curr = curr->next;
		curr2 = curr2->next;
		if (curr == a->head || curr2 == b->head)
			break ;
	}
	if (void_to_num(curr->data) == void_to_num(curr2->data))
		return (TRUE);
	return (FALSE);
}

void	push(t_stack *pt, void *x)
{
	insertLast(&pt->head, x);
	pt->size++;
}

void	push2(t_stack *pt, void *x)
{
	insertFirst(&pt->head, x);
	pt->size++;
}
