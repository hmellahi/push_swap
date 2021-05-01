#include "checker.h"
# define BUFFER_SIZE 1
int		is_valid(int fd, char **line)
{
	if (BUFFER_SIZE < 0 || !line || read(fd, NULL, 0) < 0)
		return (0);
	return (1);
}

void	free_space(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

int		saveline(char **line, char **rem, char **ptr, char **buff)
{
	char *tmp;

	**ptr = '\0';
	*ptr += 1;
	tmp = *rem;
	*rem = ft_strdup(*ptr);
	free_space(&tmp);
	*line = join(*line, *buff);
	free_space(buff);
	return (1);
}

int		checkremainder(char **remainder, char **line, char **buff)
{
	char *ptr;
	char *tmp;

	ptr = NULL;
	*line = ft_strdup("");
	if (*remainder)
	{
		if ((ptr = ft_strchr(*remainder, '\n')))
		{
			*ptr = '\0';
			*line = join(*remainder, *line);
			tmp = *remainder;
			*remainder = ft_strdup(ptr + 1);
			free_space(&tmp);
			free_space(buff);
			return (1);
		}
		else
		{
			*line = join(*remainder, *line);
			free_space(remainder);
		}
	}
	return (0);
}

int		read_line(int fd, char **line)
{
	char			*buff;
	int				nbytes;
	char			*ptr;
	static char		*rem;

	free(NULL);
	if (!is_valid(fd, line) ||
	!(buff = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (checkremainder(&rem, line, &buff))
		return (1);
	while ((nbytes = read(fd, buff, BUFFER_SIZE)))
	{
		buff[nbytes] = '\0';
		if ((ptr = ft_strchr(buff, '\n')))
			return (saveline(line, &rem, &ptr, &buff));
		*line = join(*line, buff);
	}
	free_space(&buff);
	return (0);
}