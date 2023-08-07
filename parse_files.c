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

void	print_sBox(char **sBox)
{
	for (int i = 0; sBox[i]; i++)
	{
		printf("[%d]	[%d]	[%d]	[%d]\n", (int)sBox[i][0], (int)sBox[i][1], (int)sBox[i][2], (int)sBox[i][3]);
	}
}
void	reading_s_box(t_DES *d, t_sbox *s, char **s_box)
{
	char **tmp;
	
	tmp = NULL;

	for (int i = 0; s_box[i]; i++)
	{
		tmp = my_split(s_box[i], '\t');
		s->s_box[i] = my_strdup("1234");
		for (int j = 0; tmp[j]; j++)
		{
			if (my_isdigit(tmp[j]) == 0)
			{
				free_2d_array(tmp);
				free_2d_array(s_box);
				clean_exit(d, 1);
			}
			s->s_box[i][j] = my_atoi(d, tmp, tmp[j]);
		}
		free_2d_array(tmp);
	}

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



void	reading_files_help(t_DES *d, t_sbox *s, char *file_name)
{
	int		fd;
	char	*line;
	char	**tmp_sBox;
	static int i;

	fd = open(file_name, O_RDONLY);
	tmp_sBox = malloc(sizeof(char *) * 6);
	my_bzero(tmp_sBox, sizeof(char *) * 6);
	if (fd < 0)
		closing_and_freeing(fd, NULL, 1);
	line = get_next_line(fd);
	for (int i = 0; i < 5; i++)
	{
		tmp_sBox[i] = line;
		line = get_next_line(fd);
	}
	free(line);
	reading_s_box(d, s, tmp_sBox);
	printf("file [%d][%s]\n", i++, file_name);
	print_sBox(d->sBoxs->s_box);
	close(fd);
}

void	reading_files(t_DES *d)
{
	allocating_all(d);
	for (int i = 0; i < 12; i++)
		reading_files_help(d, &d->sBoxs[i], d->files_name[i]);
	clean_exit(d, 0);
}