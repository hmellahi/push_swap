#include "checker.h"

t_string	*init_insts(void)
{
	t_string	*inst_list;

	inst_list = malloc(sizeof(char *) * 12);
	inst_list[0] = ft_strdup("sa");
	inst_list[1] = ft_strdup("sb");
	inst_list[2] = ft_strdup("ss");
	inst_list[3] = ft_strdup("pa");
	inst_list[4] = ft_strdup("pb");
	inst_list[5] = ft_strdup("ra");
	inst_list[6] = ft_strdup("rb");
	inst_list[7] = ft_strdup("rr");
	inst_list[8] = ft_strdup("rra");
	inst_list[9] = ft_strdup("rrb");
	inst_list[10] = ft_strdup("rrr");
	inst_list[11] = NULL;
	return (inst_list);
}

int	exect_inst(t_stack *fs, t_stack *ss, t_string inst, t_string *inst_list)
{
	int			index;
	t_string	ins;

	index = -1;
	while (++index < 11)
	{
		ins = inst_list[index];
		if (strcmp(inst, ins) == 0)
		{
			(run_inst(index))(fs, ss);
			return (TRUE);
		}
	}
	return (ft_exit(ERROR));
}

int	(*run_inst(int index))(t_stack *fs, t_stack *ss)
{
	int	(*funcs[12])(t_stack *fs, t_stack *ss);

	funcs[0] = swap_list_a;
	funcs[1] = swap_list_b;
	funcs[2] = swap_both;
	funcs[3] = push_in_a;
	funcs[4] = push_in_b;
	funcs[5] = rotate_a;
	funcs[6] = rotate_b;
	funcs[7] = rotate_both;
	funcs[8] = rev_rotate_a;
	funcs[9] = rev_rotate_b;
	funcs[10] = rev_rotate_both;
	funcs[11] = NULL;
	return (funcs[index]);
}
