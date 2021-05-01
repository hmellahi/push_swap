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
    }
    char *inst;
    while (read_line(0, &inst))
    {
        if (!exect_inst(list_a, list_b, inst))
            break;
    }
    if (is_sorted(list_a) && is_empty(list_b))
        ft_putstr("OK\n");
    else
        ft_putstr("KO\n");
    return (0);
}