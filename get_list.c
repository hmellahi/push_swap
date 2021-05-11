/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 06:22:03 by hamza             #+#    #+#             */
/*   Updated: 2021/05/04 21:38:09 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_index_of(t_node *pt, void *data)
{
	t_node	*curr;
	int		index;

	curr = pt;
	index = 0;
	while (1)
	{
		if (void_to_num(data) == void_to_num(curr->data))
			return (index);
		curr = curr->next;
		if (curr == pt)
			break ;
		index++;
	}
	return (index);
}

t_node	*get(t_stack *pt, int index)
{
	t_node	*curr;

	curr = pt->head;
	while (index--)
		curr = curr->next;
	return (curr);
}
