#include "checker.h"

static char	*ft_strjoin(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int	read_line(int fd, char **line)
{
	char	buffer[2];
	int		flag;

	if (!line)
		return (-1);
	*line = (char *)malloc(1);
	if (!*line)
		return (-1);
	*line[0] = '\0';
	while (flag > 0)
	{
		flag = read(fd, buffer, 1);
		if (flag == 0)
			break ;
		if (buffer[0] == '\n')
			break ;
		*line = ft_strjoin(*line, buffer[0]);
	}
	return (flag);
}
