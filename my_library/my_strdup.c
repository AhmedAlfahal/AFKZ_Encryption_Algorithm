#include"my_lib.h"

char	*my_strdup(const char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	if (!s1 || *s1 == 0)
		return (NULL);
	dup = (char *) malloc(sizeof(char) * my_strlen(s1) + 1);
	if (dup == NULL)
		return (0);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
