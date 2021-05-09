/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 06:24:21 by hamza             #+#    #+#             */
/*   Updated: 2021/05/09 02:32:32 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*deletefirst(t_node **head)
{
	t_node	*temp;

	temp = *head;
	if ((*head)->next == (*head))
	{
		(*head) = NULL;
		return (NULL);
	}
	(*head)->next->prev = (*head)->prev;
	(*head)->prev->next = (*head)->next;
	(*head) = (*head)->next;
	free(temp->data);
	free(temp);
	return (temp);
}
