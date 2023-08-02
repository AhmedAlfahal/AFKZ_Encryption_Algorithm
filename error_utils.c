#include "DES.h"

void	closing_and_freeing(int fd, char *line, int ext)
{
	if (fd >= 0)
		close(fd);
	free(line);
	if (ext == 1)
	{
		write(2, "Error\nInvalid file\n", 20);
		exit(1);
	}
}