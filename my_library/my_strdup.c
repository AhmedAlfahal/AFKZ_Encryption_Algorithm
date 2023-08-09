#include"my_lib.h"

char	**dupper_2d(char **source)
{
	int	i;
	char **tmp = NULL;

	i = my_strlen_2d(source);
	tmp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (source[i])
	{
		tmp[i] = my_strdup(source[i]);
		i++;
	}
	tmp[i]= NULL;
	return (tmp);
}

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
