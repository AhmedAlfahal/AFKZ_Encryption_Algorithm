#include "../AFKZ.h"

int main(int ac, char **av)
{
	t_DES d;
	if (ac == 3)
	{
		reading_files(&d);
		reading_keys(&d, av[1]);
		d.plain = av[2];
		encrypt(&d);
		decrypt(&d);
		clean_exit(&d, 0, 0);
	}
	else
	{
		write(2, "Wrong usage\nUsage: ./AFKZ_encryption [Key][Plain Tex]\n", 55);
	}
}