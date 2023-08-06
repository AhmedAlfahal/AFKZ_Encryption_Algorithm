#include "DES.h"

// void	

void	reading_files(t_DES *d)
{
	int		fd;
	int		number_of_lines;
	char	*line;

	number_of_lines = 0;
	fd = open("tables/keys.DES", O_RDONLY);
	if (fd < 0)
		closing_and_freeing(fd, NULL, 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		number_of_lines++;
		free(line);
		line = get_next_line(fd);
	}
	d->keys = malloc(sizeof(int *) * (number_of_lines + 1));
	number_of_lines = 0;
	free(line);
	close(fd);
	fd = open("tables/s_box.DES", O_RDONLY);
	if (fd < 0)
		closing_and_freeing(fd, NULL, 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		number_of_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	
}

int main(int ac, char **av)
{
	t_DES *d;

	if (ac == 2)
	{
		d = malloc(sizeof(t_DES) * 1);
		txtBin2int(d, av[1]);
	}
	else
	{
		write(2, "Wrong Inputs\nUsage: ./SimplifiedDES [binary_txt]\n", 50);
	}
}