
#include "minishell.h"

/*
TODO:
	-Make it more readable.
	-
*/

#undef BUFF_SIZE
# define BUFF_SIZE 128

static int		ft_free(char **fr1, char **fr2)
{
	if (fr1)
	{
		free(*fr1);
		*fr1 = NULL;
	}
	if (fr2)
	{
		free(*fr2);
		*fr2 = NULL;
	}
	return (-1);
}

static int		got_line(char **fd_table, char **buff, char **line)
{
	char		*fr1;

	ft_free(buff, NULL);
	if (!(*line = ft_substr(*fd_table, 0, ft_line_len(*fd_table))))
		return (-1);
	fr1 = *fd_table;
	if (!(*fd_table = ft_strdup(*fd_table + ft_line_len(*fd_table) + 1)))
	{
		ft_free(&fr1, NULL);
		return (-1);
	}
	ft_free(&fr1, NULL);
	return (1);
}

int		gnl(int fd, char **line)
{
	ssize_t		read_ret;
	char		*p;
	char		*buff;
	static char *fd_table[OPEN_MAX];

	if (fd < 0 || !line || BUFF_SIZE < 0
		|| read(fd, NULL, 0) || !(buff = malloc(BUFF_SIZE + 1)))
		return (-1);
	if (!fd_table[fd] && !(fd_table[fd] = ft_strdup("")))
			return (-1);
	while (!ft_find(fd_table[fd], '\n') && (read_ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_ret] = '\0';
		p = fd_table[fd];
		if (!(fd_table[fd] = ft_strjoin(fd_table[fd], buff)))
			return (ft_free(&p, NULL));
		ft_free(&p, NULL);
	}
	if (ft_find(fd_table[fd], '\n'))
		return (got_line(&fd_table[fd], &buff, line));
	if (!(*line = ft_strdup(fd_table[fd])))
		return (-1);
	ft_free(&fd_table[fd], &buff);
	return (read_ret > 0 ? 1 : read_ret);
}
