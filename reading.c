/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 01:50:40 by hamza             #+#    #+#             */
/*   Updated: 2021/05/08 03:12:25 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	insert_nums(t_stack *list_a, int ac, char **av)
{
	int		i;
	int		j;
	long	*k;

	i = 0;
	while (++i <= ac)
	{
		j = -1;
		while (++j < ft_strlen(av[i]))
		{
			if (!is_digit(av[i][j]))
				ft_exit(ERROR);
		}
		k = malloc(sizeof(long));
		*k = ft_atoi(av[i]);
		if (!is_unique(list_a, (int *)k) || *k < 0)
			ft_exit(ERROR);
		push(list_a, k);
	}
}
