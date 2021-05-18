/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmellahi <hmellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 06:45:29 by hamza             #+#    #+#             */
/*   Updated: 2021/05/18 17:21:59 by hmellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_first_index(t_stack *list_a, int max_of_cc, int *first_index)
{
	int	i;
	int	hold_first;
	int	half;

	*first_index = 9999;
	half = list_a->size / 2;
	i = -1;
	while (++i < list_a->size)
	{
		hold_first = void_to_num(get(list_a, i)->data);
		if (hold_first <= max_of_cc)
		{
			*first_index = i;
			break ;
		}
	}
	if (*first_index >= half && *first_index != 9999)
		*first_index -= list_a->size;
	return (hold_first);
}

int	get_sec_index(t_stack *list_a, int max_of_cc, int *sec_index,
int first_index)
{
	int	i;
	int	hold_sec;
	int	half;

	*sec_index = 9999;
	i = list_a->size;
	half = list_a->size / 2;
	while (--i > first_index)
	{
		hold_sec = void_to_num(get(list_a, i)->data);
		if (hold_sec <= max_of_cc)
		{
			*sec_index = i;
			break ;
		}
	}
	if (*sec_index >= half && *sec_index != 9999)
		*sec_index -= list_a->size;
	return (hold_sec);
}

int	sort(t_stack *sorted_list, int chunk_index, t_stack *list_a, t_stack *list_b)
{
	int	first_index;
	int	sec_index;
	int	max_of_cc;
	int	index;

	max_of_cc = void_to_num(get(sorted_list, chunk_index - 1)->data);
	get_first_index(list_a, max_of_cc, &first_index);
	get_sec_index(list_a, max_of_cc, &sec_index, first_index);
	if (abs(first_index) > abs(sec_index))
		index = sec_index;
	else
		index = first_index;
	move_to_top(list_a, index);
	if (!is_empty(list_a) && is_equal(sorted_list, list_a) == TRUE)
		return (ft_exit(COMPLETED));
	push_in_b(list_a, list_b);
	return (0);
}

int	sort_n_nums( t_stack *sorted_list, t_stack *list_a, t_stack *list_b)
{
	int	chunk_index;
	int	chunk_size;
	int	i;

	chunk_size = 2;
	if (list_a->size == 2)
		chunk_size = 1;
	else if (list_a->size == 500)
		chunk_size = list_a->size / 10;
	else if (list_a->size >= 100)
		chunk_size = list_a->size / 5;
	chunk_index = 0;
	i = 0;
	while (!is_empty(list_a))
	{
		if (i % chunk_size == 0)
			chunk_index += chunk_size;
		sort(sorted_list, chunk_index, list_a, list_b);
		i++;
	}
	moves_back_to_a(list_a, list_b, sorted_list);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*list_a;
	t_stack	*list_b;
	t_stack	*sorted_list;

	list_a = newStack('a');
	list_b = newStack('b');
	if (ac == 1)
		return (ft_exit(COMPLETED));
	insert_nums(list_a, --ac, av);
	sorted_list = cpy(list_a);
	bubble_sort(&sorted_list->head);
	if (is_equal(sorted_list, list_a) == TRUE)
		return (ft_exit(COMPLETED));
	if (list_a->size == 3)
		sort_three_nums(list_a);
	else if (list_a->size == 5)
		sort_five_nums(sorted_list, list_a, list_b);
	else
		sort_n_nums(sorted_list, list_a, list_b);
	free_stack(&sorted_list);
	free_stack(&list_a);
	free_stack(&list_b);
}
