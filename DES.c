#include "DES.h"

int main(int ac, char **av)
{
	t_DES d;

	if (ac == 2)
	{
		txtBin2int(&d, av[1]);
	}
	else
	{
		write(2, "Wrong Inputs\nUsage: ./SimplifiedDES [binary_txt]\n", 50);
	}
}