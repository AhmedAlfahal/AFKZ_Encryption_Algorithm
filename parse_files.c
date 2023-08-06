#include "DES.h"
#include "my_library/my_lib.h"
#include <stdio.h>

void	print_2d_array(char **d)
{
	int	i;

	i = 0;
	while (d[i])
		printf("[%s]\n", d[i++]);
}

void	allociting_sBoxes(t_DES *d)
{
	d->sBoxs = malloc(sizeof(t_sbox) * (11));
	my_bzero(d->sBoxs, 11);
	for (int i = 0; i < 11; i++)
	{
		d->sBoxs[i].s_box = malloc (sizeof(char *) * 5);
		d->sBoxs[i].s_box[4] = NULL;
		d->sBoxs[i].iS_box = malloc (sizeof(char *) * 5);
		d->sBoxs[i].iS_box[4] = NULL;
	}
}



void	reading_files(t_DES *d)
{
	int		fd;
	int		number_of_lines;
	char	*line;

	number_of_lines = 0;
	allociting_sBoxes(d);
	fd = open("tables/s_box.DES", O_RDONLY);
	// if (fd < 0)
	// 	closing_and_freeing(fd, NULL, 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		d->sBoxs[0].s_box[number_of_lines++] = line;
		line = get_next_line(fd);
	}
	d->sBoxs[0].s_box[number_of_lines] = NULL;
	print_2d_array(d->sBoxs[0].s_box);
	close(fd);

}