
#include "minishell.h"


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
	char			*sub;
	unsigned int	sublen;
	unsigned int	i;

	if (!s)
		return (NULL);
	sublen = str_len(s);
	if (start > sublen)
		return (str_dup(""));
	if (len > sublen)
		len = sublen;
	if (!(sub = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
