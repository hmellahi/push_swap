/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:22:11 by hmellahi          #+#    #+#             */
/*   Updated: 2021/05/04 21:17:45 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_cmds(t_stack *list_a, t_stack *list_b)
{
	int		nbytes;
	char	*inst;

	nbytes = 1;
	while (nbytes)
	{
		nbytes = read_line(0, &inst);
		if (!nbytes && ft_strlen(inst) == 0)
			break ;
		exect_inst(list_a, list_b, inst);
	}
}

int	main(int ac, char **av)
{
	t_stack	*list_a;
	t_stack	*list_b;

	list_a = newStack('a');
	list_b = newStack('b');
	if (ac == 0)
		return (ft_exit(NONE));
	insert_nums(list_a, list_b, --ac, av);
	read_cmds(list_a, list_b);
	display(list_a);
	if (is_sorted(list_a) && is_empty(list_b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
