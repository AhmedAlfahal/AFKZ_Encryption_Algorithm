#include"my_lib.h"

char	*my_substr(char const *s, unsigned int start, int len)
{
	char	*sub;
	int	i;
	int		k;

	i = 0;
	k = start;
	if (!s)
		return (NULL);
	if (start > (unsigned int)my_strlen(s))
		return (my_strdup(""));
	if (len > my_strlen(s))
	{
		sub = malloc(sizeof(char) * (my_strlen(s) - start) + 1);
		if (!sub)
			return (NULL);
		len = my_strlen(s);
	}
	else
		sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[start] != '\0' && i < len - k)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
