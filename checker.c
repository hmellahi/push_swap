/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:22:11 by hmellahi          #+#    #+#             */
/*   Updated: 2021/05/09 18:49:02 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_cmds(t_stack *list_a, t_stack *list_b)
{
	int			nbytes;
	char		*inst;
	t_string	*inst_list;

	nbytes = 1;
	inst_list = init_insts();
	while (nbytes)
	{
		nbytes = read_line(0, &inst);
		if (!nbytes && ft_strlen(inst) == 0)
			break ;
		exect_inst(list_a, list_b, inst, inst_list);
		free(inst);
	}
	free(inst);
	nbytes = -1;
	while (inst_list[++nbytes])
		free(inst_list[nbytes]);
	free(inst_list);
}

int	main(int ac, char **av)
{
	t_stack	*list_a;
	t_stack	*list_b;

	list_a = newStack('a');
	list_b = newStack('b');
	if (ac == 1)
		return (ft_exit(NONE));
	insert_nums(list_a, --ac, av);
	read_cmds(list_a, list_b);
	display(list_a);
	if (is_sorted(list_a) && is_empty(list_b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(&list_a);
	free_stack(&list_b);
	return (0);
}
