#include "../AFKZ.h"

int main(int ac, char **av)
{
	t_DES d;
	if (ac == 3)
	{
		reading_files(&d);
		reading_keys(&d, av[1]);
	}
	else
	{
		write(2, "Wrong usage\nUsage: ./AFKZ_encryption [Key][Plain Tex]\n", 55);
	}
}