/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmellahi <hmellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:12:33 by hamza             #+#    #+#             */
/*   Updated: 2021/05/02 16:18:51 by hmellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char const s)
{
	write(1, &s, 1);
}

int	void_to_num(void *x)
{
	return (*((int *)x));
}

void	ft_putnbr(int nb)
{
	long int	c;

	c = nb;
	if (c < 0)
	{
		ft_putchar('-');
		c = -c;
	}
	if (c > 9)
	{
		ft_putnbr(c / 10);
		ft_putnbr(c % 10);
	}
	else
		ft_putchar(c + '0');
}

int	ft_strcmp(char *s1, const char *s2)
{
	int	x;

	x = 0;
	while (s1[x] == s2[x] && s1[x] != '\0' && s2[x] != '\0')
		x++;
	return (s1[x] - s2[x]);
}

void	ft_putstr(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
