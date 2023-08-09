#include "../AFKZ.h"

unsigned int	getting_bit(unsigned char c, int n)
{
	unsigned char tmp = c;
	int bit = ((unsigned char)tmp >> n) & 1;
	return (bit);
}

unsigned int	new_i(unsigned int s)
{
	return ((s & 12) >> 2);
}

unsigned int	new_j(unsigned int s)
{
	return (s & 3);
}

unsigned int get_left(unsigned int s)
{
	return (s & 15);
}

unsigned int	get_right(unsigned int s)
{
	return ((s >> 4) & 15);
}

unsigned char	s_boxing(char **sl, char **sr, unsigned char c)
{
	unsigned char	new;
	unsigned char cl = get_left(c);
	unsigned char cr = get_right(c);
	cl = sl[new_i(cl)][new_j(cl)];
	cr = sr[new_i(cr)][new_j(cr)];
	new = cl;
	new = (new << 4);
	new = new ^ cr;
	return (new);
}