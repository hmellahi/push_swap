/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 06:23:10 by hamza             #+#    #+#             */
/*   Updated: 2021/05/04 06:23:27 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	freeList(t_node **head)
{
	t_node	*curr;
	t_node	*tmp;

	curr = *head;
	while (curr->next != *head)
	{
		tmp = curr->next;
		free(curr->data);
		free(curr);
		curr = tmp;
	}
}
