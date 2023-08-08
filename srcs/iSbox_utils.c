#include "../AFKZ.h"


static int	new_s(int i, int j)
{
	int ii = (i << 2);
	return (ii ^ j);
}

static int	new_i(int s)
{
	return ((s & 12) >> 2);
}

static int	new_j(int s)
{
	return (s & 3);
}

void	creating_inverse(t_sbox *s)
{
	printf("---------------------Inverse-------------\n");
	for (int i = 0; i < 4; i++)
		s->iS_box[i] = my_strdup("1234");
	for (int i = 0; s->s_box[i]; i++)
		for (int j = 0; j < 4; j++)
		{
			s->iS_box[new_i(s->s_box[i][j])][new_j(s->s_box[i][j])] = new_s(i, j);
		}
	print_Box(s->iS_box, 1);
}

// void	