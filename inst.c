#include "checker.h"

t_string inst_list[11] = {
    "sa",
    "sb",
    "ss",
    "pa",
    "pb",
    "ra",
    "rb",
    "rr",
    "rra",
    "rrb",
    "rrr"
};

int exect_inst(t_stack *fs, t_stack *ss, t_string inst)
{
    int index;

    index = -1;
    while (++index < 11)
        if (strcmp(inst_list[index], inst) == 0)
        {
            (run_inst(index))(fs, ss);
            return (TRUE);
        }
    ft_exit(ERROR);
    return (FALSE);
}

int (*run_inst(int index))(t_stack *fs, t_stack *ss)
{
    int (*funcs[12])(t_stack * fs, t_stack * ss);

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
    return funcs[index];
}
