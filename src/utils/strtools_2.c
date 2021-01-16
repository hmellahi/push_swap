
#include "minishell.h"

t_bool	find_eol(char *buff)
{
	if (!buff)
		return (FALSE);
	return (char_addr(EOL, buff) ? TRUE : FALSE);
}

size_t	line_len(const char *line)
{
	//return ((size_t)char_addr(EOL, line) - line);
	return 0;
}

t_bool	line_isempty(char *line)
{
	if (line[0] == EOL && line[1] == 0)
		return (TRUE);
	return (FALSE);
}

char	*str_dup(const char *str)
{
	size_t			i;
	size_t			len;
	char			*dup;

	len = str_len(str);
	//ARRLLOC(dup, len + 1);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (0);
	dup[len] = 0;
	i = -1;
	while (++i < len)
		dup[i] = str[i];
	return (dup);
}
