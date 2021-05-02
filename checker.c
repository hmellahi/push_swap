#include "checker.h"
int main(int ac, char **av)
{
    int i;
    int j;
    int x;
    long *k;
    t_stack *list_a;
    t_stack *list_b;

    list_a = newStack('a');
    list_b = newStack('b');
    i = 0;
    ac--;
    if (ac == 0)
        return (ft_exit(NONE));
    while (++i <= ac)
    {
        j = -1;
        while (++j < strlen(av[i]))
        {
            x = av[i][j];
            if (!is_digit(x))
                return (ft_exit(ERROR));
        }
        k = malloc(sizeof(long));
        *k = ft_atoi(av[i]);
        //printf("%ld\n", *k);
        if (!is_unique(list_a, (int*)k) || *k < 0)
            return (ft_exit(ERROR));
        push(list_a, k);
        //free(k);
    }
    int nbytes;
    char *inst;
    nbytes = 1;
    while (nbytes)
    {
        nbytes = read_line(0, &inst);
        if (!exect_inst(list_a, list_b, inst))
            break;
        free(inst);
    }
    // free(inst);
    //display(list_a);
    if (is_sorted(list_a) && is_empty(list_b))
        ft_putstr("OK\n");
    else
        ft_putstr("KO\n");
    free_stack(list_a);
    free_stack(list_b);
    return (0);
}

// ./checker 0 9 1 8 2 (instr: pb ra pb ra sa ra pa pa)
// ./checker 4 1 6 2 7 3 (instr: pb ra sa pa rb rrb rra)
//  ./checker 0 1 2 (instr: none)