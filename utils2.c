#include "checker.h"

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int ft_exit(int status)
{
    if (status == ERROR)
        ft_putstr("Error\n");
    // free garbage [TODO]
    exit(status);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_atoi(const char *str)
{
	int neg;
	int i;
	long num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
        if (num >= 2147483647)
            return (-1);
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}