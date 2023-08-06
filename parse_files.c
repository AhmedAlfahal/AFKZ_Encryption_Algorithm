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

void	allocating_all(t_DES *d)
{
	d->sBoxs = malloc(sizeof(t_sbox) * 13);
	my_bzero(d->sBoxs, 13);
	for (int i = 0; i < 13; i++)
	{
		d->sBoxs[i].s_box = malloc (sizeof(char *) * 5);
		my_bzero(d->sBoxs[i].s_box, sizeof(char *) * 5);
		d->sBoxs[i].iS_box = malloc (sizeof(char *) * 5);
		my_bzero(d->sBoxs[i].iS_box, sizeof(char *) * 5);
	}
	d->files_name = malloc(sizeof(char *) * 12);
	my_bzero(d->files_name, sizeof(char *) * 12);
	d->files_name[0] = strdup("tables/s_box1.DES");
	d->files_name[1] = strdup("tables/s_box2.DES");
	d->files_name[2] = strdup("tables/s_box3.DES");
	d->files_name[3] = strdup("tables/s_box4.DES");
	d->files_name[4] = strdup("tables/s_box5.DES");
	d->files_name[5] = strdup("tables/s_box6.DES");
	d->files_name[6] = strdup("tables/s_box7.DES");
	d->files_name[7] = strdup("tables/s_box8.DES");
	d->files_name[8] = strdup("tables/s_box9.DES");
	d->files_name[9] = strdup("tables/s_box10.DES");
	d->files_name[10] = strdup("tables/p_box1.DES");
	d->files_name[11] = strdup("tables/p_box2.DES");
}



void	reading_files_help(t_sbox *s, char *file_name)
{
	int		fd;
	char	*line;
	static int i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		closing_and_freeing(fd, NULL, 1);
	line = get_next_line(fd);
	for (int i = 0; i < 5; i++)
	{
		s->s_box[i] = line;
		line = get_next_line(fd);
	}
	print_2d_array(s->s_box);
	printf("file [%d][%s]\n", i++, file_name);
	close(fd);
}

void	reading_files(t_DES *d)
{
	allocating_all(d);
	for (int i = 0; i < 12; i++)
		reading_files_help(&d->sBoxs[i], d->files_name[i]);
}