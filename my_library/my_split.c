#include"my_lib.h"

static int	sep_count(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c && (s[1] == c || s[1] == '\0'))
			i++;
		s++;
	}
	return (i);
}

static size_t	next_sep(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (my_strlen(s));
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		seps;
	char	**split;

	if (!s)
		return (NULL);
	j = 0;
	seps = sep_count(s, c);
	split = (char **)malloc(sizeof(char *) * (seps + 1));
	if (!split)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (j < seps)
			split[j++] = my_substr(s, 0, next_sep(s, c));
		while (*s != c && *s)
			s++;
	}
	split[j] = 0;
	return (split);
}
