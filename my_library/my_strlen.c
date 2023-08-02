#include"my_lib.h"

int	my_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s || *s == '\0')
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
