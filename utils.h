/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:37:17 by hmellahi          #+#    #+#             */
/*   Updated: 2021/04/30 22:38:30 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int    swap(t_stack *stack);
int    swap_list_a(t_stack *fs, t_stack *ss);
int    swap_list_b(t_stack *fs, t_stack *ss);
int    swap_both(t_stack *fs, t_stack *ss);
int    rev_rotate(t_stack *stack);
int    push_in_a(t_stack *fs, t_stack *ss);
int    push_in_b(t_stack *fs, t_stack *ss);
int    rotate(t_stack *stack);
int    rotate_a(t_stack *fs, t_stack *ss);
int    rotate_b(t_stack *fs, t_stack *ss);
int    rev_rotate_both(t_stack *fs, t_stack *ss);
int    rev_rotate_b(t_stack *fs, t_stack *ss);
int    rev_rotate_a(t_stack *fs, t_stack *ss);
int    rotate_both(t_stack *fs, t_stack *ss);
int     void_to_num(void* x);
void	ft_putchar(char const s);
int	ft_strcmp(char *s1, const char *s2);
void	ft_putnbr(int nb);
void	ft_putstr(char const *s);
