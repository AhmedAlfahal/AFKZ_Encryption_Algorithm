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

void	free_2d_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s[i]);
	free(s);
}

void	free_all(t_DES *d)
{
	for (int i = 0; i < 13; i++)
	{
		
	}
}