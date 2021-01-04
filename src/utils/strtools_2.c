
#include "minishell.h"

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

char	*str_join(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	l;
	char			*s3;

	if (!s1 || !s2)
		return (NULL);
	i = str_len(s1) + str_len(s2);
	if (!(s3 = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	s3[i] = '\0';
	i = 0;
	while (s1[i])
	{
		s3[i] = (char)s1[i];
		i++;
	}
	l = 0;
	while (s2[l])
	{
		s3[i++] = (char)s2[l];
		l++;
	}
	return (s3);
}

char	*sub_str(char const *s, size_t start, size_t len)
{
	unsigned int	i;
	unsigned int	slen;
	char			*s2;

	if (!s)
		return (NULL);
	slen = str_len(s);
	if (start > slen)
		return (str_dup(""));
	if (len > slen)
		len = slen;
	if (!(s2 = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len && s[start])
		s2[i++] = s[start++];
	s2[i] = '\0';
	return (s2);
}
