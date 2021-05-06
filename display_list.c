/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 06:21:20 by hamza             #+#    #+#             */
/*   Updated: 2021/05/04 06:27:16 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void display_list(t_node *head, int type)
{
	t_node *ptr = head;
	ft_putstr("\n[ ");
	while (ptr != NULL)
	{
		if (type == INT) {
			ft_putnbr(void_to_num(ptr->data));
			fflush(stdout);
		}
		else
			ft_putstr(ptr->data);
		ptr = ptr->next;
		ft_putstr("|");
		if (ptr == head)
			break;
	}
	ft_putstr(" ]\n");
}