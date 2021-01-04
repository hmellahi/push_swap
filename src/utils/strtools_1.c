
#include "minishell.h"

char	*char_addr(char c, char *buff)
{
	while (*buff)
		if (*buff == c)
			return (buff);
		else
            buff++;
	return (NULL);
}

t_bool	find_eol(char *buff)
{
	if (NOT buff)
        return (FALSE);
	return (char_addr(EOL, buff) ? TRUE : FALSE);
}

size_t	line_len(const char *line)
{
	return 0;
	//return ((size_t)char_addr(EOL, line) - line);
}

t_bool	line_isempty(char *line)
{
	if (line[0] == EOL AND line[1] == 0)
		return (TRUE);
	return (FALSE);
}

t_bool  str_cmp(char *s1, char *s2)
{
	size_t len1;
	size_t len2;

	if (s1 == NULL && s2 == NULL)
		return 1;
	if (s1 == NULL || s2 == NULL)
		return (0);
	len1 = str_len(s1);
	len2 = str_len(s2);
	if (len1 != len2)
        return (0);
	len1++;
	while (len1--)
		if (s1[len1] != s2[len1])
			return (0);
	return (1);
}

t_bool  str_ncmp(char *s1, char *s2, int max)
{
	size_t len;

	if (s1 == NULL && s2 == NULL)
		return 1;
	if (s1 == NULL || s2 == NULL || max < 1)
		return (0);
	len = 0;
	while (s1[len] && s2[len] && max--)
		if (s1[len] != s2[len])
			return (0);
		else
			len++;
	return (1);
}
