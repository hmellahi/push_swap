/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:51:48 by hmellahi          #+#    #+#             */
/*   Updated: 2021/05/08 03:19:20 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	bubble_sort(t_node **headRef)
{
	t_node	*itr;
	t_node	*itr2;
	t_node	*head;
	int		*temp;

	head = *headRef;
	itr = head;
	while (itr->next != head)
	{
		itr2 = itr->next;
		while (itr2 != head)
		{
			if (void_to_num(itr->data) > void_to_num(itr2->data))
			{
				temp = itr->data;
				itr->data = itr2->data;
				itr2->data = temp;
			}
			itr2 = itr2->next;
		}
		itr = itr->next;
	}
}
