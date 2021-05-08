#include "checker.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*dest;

	len = ft_strlen((char *)str);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	dest[len] = 0;
	while (len--)
		dest[len] = ((char *)str)[len];
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c && *str)
		str++;
	if (*str != c)
		return (0);
	return (str);
}

char	*join(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*s12;

	k = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s12 = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!s12)
		return (NULL);
	while (s1[i])
	{
		s12[i] = s1[i];
		i++;
	}
	while (s2[k])
		s12[i++] = s2[k++];
	s12[i] = 0;
	return (s12);
}
