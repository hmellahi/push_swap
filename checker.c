/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmellahi <hmellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:22:11 by hmellahi          #+#    #+#             */
/*   Updated: 2021/05/02 17:31:25 by hmellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    read_cmds(t_stack *list_a, t_stack *list_b)
{
    int     nbytes;
    char    *inst;

    nbytes = 1;
    while (nbytes)
    {
        nbytes = read_line(0, &inst);
        if (!nbytes && ft_strlen(inst) == 0)
            break;
        exect_inst(list_a, list_b, inst);
        free(inst);
    }
}

void    insert_nums(t_stack *list_a, t_stack *list_b, int ac, char **av)
{
    int i;
    int j;
    long *k;

    i = 0;
    while (++i <= ac)
    {
        j = -1;
        while (++j < strlen(av[i]))
        {
            if (!is_digit(av[i][j]))
                ft_exit(ERROR);
        }
        k = malloc(sizeof(long));
        *k = ft_atoi(av[i]);
        if (!is_unique(list_a, (int*)k) || *k < 0)
            ft_exit(ERROR);
        push(list_a, k);
    }
}

int main(int ac, char **av)
{
    t_stack *list_a;
    t_stack *list_b;

    list_a = newStack('a');
    list_b = newStack('b');
    if (ac == 0)
        return (ft_exit(NONE));
    insert_nums(list_a, list_b, ac, av);
    read_cmds(list_a, list_b);
    if (is_sorted(list_a) && is_empty(list_b))
        ft_putstr("OK\n");
    else
        ft_putstr("KO\n");
    system("leaks checker");
    return (0);
}