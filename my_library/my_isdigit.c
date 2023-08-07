#include "my_lib.h"

int	my_isdigit(char *s)
{
	int x = 0;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			x = 1;
		else
			return (0);
	}
	return (x);
}
