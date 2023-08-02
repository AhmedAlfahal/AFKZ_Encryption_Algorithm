#include "my_lib.h"

int	my_filecmp(const char *s1, const char *s2, int n)
{
	int				i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (a[n] == b[i] && a[n] != '\0' && b[i] != '\0')
	{
		if (a[n + 2] == '\0' && b[i + 2] == '\0')
		{
			return (0);
		}
		n++;
		i++;
	}
	return (1);
}
