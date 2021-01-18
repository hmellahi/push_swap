
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

char	*sub_str(char const *s, int start, int end)
{
	char		*sub;
	size_t		len;
	size_t		i;

	if (!s)
		return (NULL);
	len = str_len(s);
	if (start > (int)len || end < 0)
		return (str_dup(""));
	start = start < 0 ? 0 : start;
	end = end >= len ? len : end;
	if (!(sub = malloc(end - start + 1)))
		return (NULL);
	i = 0;
	while (start < end && s[start])
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[start] = '\0';
	return (sub);
}
