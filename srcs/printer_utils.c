#include "../AFKZ.h"

void	print_2d_array(char **d)
{
	int	i;

	i = 0;
	while (d[i])
		printf("[%s]\n", d[i++]);
}

void	print_Box(char **sBox, int msg)
{
	char *s = sBox[0];
	if (msg == 1)
	{
		for (int i = 0; sBox[i]; i++)
		{
			for (int j = 0; j < 4; j++)
				printf("	[%d]	", (int)sBox[i][j]);
			printf("\n");
		}
	}
	else if (msg == 3)
	{
		for (int i = 0; sBox[i]; i++)
		{
			for (int j = 0; j < 8; j++)
				printf("	[%d]	", (int)sBox[i][j]);
			printf("\n");
		}
	}
	else if (msg == 2)
	{
		for (int j = 0; j < 8; j++)
			printf("	[%d]	", (int)s[j]);
		printf("\n");
	}
}


void printBinary(unsigned char v) {
  int i; // for C89 compatability
  for(i = 7; i >= 0; i--) putchar('0' + ((v >> i) & 1));
}
