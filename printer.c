#include "DES.h"

void	print_2d_array(char **d)
{
	int	i;

	i = 0;
	while (d[i])
		printf("[%s]\n", d[i++]);
}

void	print_sBox(char **sBox)
{
	for (int i = 0; sBox[i]; i++)
	{
		printf("[%d]	[%d]	[%d]	[%d]\n", (int)sBox[i][0], (int)sBox[i][1], (int)sBox[i][2], (int)sBox[i][3]);
	}
}
