/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmellahi <hmellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 06:36:34 by hamza             #+#    #+#             */
/*   Updated: 2021/05/05 15:42:58 by hmellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int peek(t_stack *pt)
{
	t_node *fs_node;

	if (pt->size == 0)
		return (-1);
	fs_node = pt->head;
	return (void_to_num(fs_node->data));
}

int pop(t_stack *pt)
{
	int first_num;

	if (pt->size == 0)
		return (-1);
	first_num = peek(pt);
	deleteFirst(&pt->head);
	return (first_num);
}
#define DEBUG 0
void display(t_stack *pt)
{
	if (!DEBUG)
		return;
	if (pt->size == 0)
		return;
	display_list(pt->head, pt->type);
}

int is_sorted(t_stack *pt)
{
	int min;
	t_node *curr;
	t_node *head;

	min = -1;
	head = (t_node *)pt->head;
	curr = head;
	while (1)
	{
		if (void_to_num(curr->data) < min)
			return (FALSE);
		min = void_to_num(curr->data);
		curr = curr->next;
		if (curr == head)
			break;
	}
	return (TRUE);
}

int is_empty(t_stack *pt)
{
	return (pt->size == 0);
}