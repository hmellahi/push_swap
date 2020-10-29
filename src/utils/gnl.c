
#include "../../include/minishell.h"

#undef BUFF_SIZE
# define BUFF_SIZE 64

int		ft_free(char **fr1, char **fr2)
{
	if (fr1 != NULL)
	{
		free(*fr1);
		*fr1 = NULL;
	}
	if (fr2 != NULL)
	{
		free(*fr2);
		*fr2 = NULL;
	}
	return (-1);
}

int		got_line(char **fd_table, char **br, char **line)
{
	char		*fr1;

	ft_free(br, NULL);
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
	ssize_t		bf;
	char		*fr;
	char		*br;
	static char *fd_table[GNL_OPEN_MAX];

	if (fd < 0 || !line || BUFF_SIZE < 0
		|| read(fd, NULL, 0) || !(br = malloc(BUFF_SIZE + 1)))
		return (-1);
	if (!fd_table[fd] && !(fd_table[fd] = ft_strdup("")))
			return (-1);
	while (!ft_find(fd_table[fd], '\n') && (bf = read(fd, br, BUFF_SIZE)) > 0)
	{
		br[bf] = '\0';
		fr = fd_table[fd];
		if (!(fd_table[fd] = ft_strjoin(fd_table[fd], br)))
			return (ft_free(&fr, NULL));
		ft_free(&fr, NULL);
	}
	if (ft_find(fd_table[fd], '\n'))
		return (got_line(&fd_table[fd], &br, line));
	if (!(*line = ft_strdup(fd_table[fd])))
		return (-1);
	ft_free(&fd_table[fd], &br);
	return (bf > 0 ? 1 : bf);
}
