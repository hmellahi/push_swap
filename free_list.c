/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 06:23:10 by hamza             #+#    #+#             */
/*   Updated: 2021/05/10 20:25:56 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	freeList(t_node **head)
{
	t_node	*curr;
	t_node	*tmp;

	curr = *head;
	while (curr != NULL)
	{
		tmp = curr->next;
		free(curr->data);
		free(curr);
		curr = tmp;
		if (curr == *head)
			break ;
	}
}

void	free_stack(t_stack **list)
{
	freeList(&(*list)->head);
	free(*list);
}
