#include "../AFKZ.h"

static void validate_value(t_AFKZ *d, char **tmp, int value, int condition)
{
	if (condition == 1)
	{
		if (value > 15 || value < 0)
		{
			free_2d_array(tmp);
			clean_exit(d, 1, 3);
		}
	}
	else if (condition == 2)
	{
		if (value > 39 || value < 0)
		{
			free_2d_array(tmp);
			clean_exit(d, 1, 5);
		}
	}
	else if (condition == 3)
	{
		if (value > 7 || value < 0)
		{
			free_2d_array(tmp);
			clean_exit(d, 1, 6);
		}
	}
}

static void	allocating_all(t_AFKZ *d)
{
	d->sBoxs = malloc(sizeof(t_sbox) * 11);
	my_bzero(d->sBoxs, sizeof(t_sbox) * 11);
	d->pTables = malloc(sizeof(t_pTable) * 1);
	my_bzero(d->pTables, sizeof(t_pTable) * 1);
	d->pTables->key_pTable = malloc(sizeof(char *) * 6);
	my_bzero(d->pTables->key_pTable, sizeof(char *) * 6);
	d->pTables->text_pTable = malloc(sizeof(char) * 9);
	my_bzero(d->pTables->text_pTable, sizeof(char) * 9);
	d->pTables->text_ipTable = malloc(sizeof(char) * 9);
	my_bzero(d->pTables->text_ipTable, sizeof(char) * 9);
	d->keys.sub_keys = malloc(sizeof(char *) * 6);
	my_bzero(d->keys.sub_keys, sizeof(char *) * 6);
	for (int i = 0; i < 11; i++)
	{
		d->sBoxs[i].s_box = malloc (sizeof(char *) * 5);
		my_bzero(d->sBoxs[i].s_box, sizeof(char *) * 5);
		d->sBoxs[i].iS_box = malloc (sizeof(char *) * 5);
		my_bzero(d->sBoxs[i].iS_box, sizeof(char *) * 5);
	}
	d->files_name = malloc(sizeof(char *) * 13);
	my_bzero(d->files_name, sizeof(char *) * 13);
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

static void	validate_sBox(t_AFKZ *d, char **s, char *ss, int msg)
{
	int tmp = -1;
	if (msg == 1)
	{
		for (int i = 0; s[i]; i++)
		{
			for (int j = 0; j < s[i][j]; j++)
			{
				tmp = (int)s[i][j];
				for (int k = i; s[k]; k++)
				{
					for (int l = 0; s[k][l]; l++)
					{
						if (i == k && j == l)
							continue;
						else if (tmp == s[k][l])
							clean_exit(d, 1, 2);
					}
				}
			}
		}
	}
	else if (msg == 2)
	{
		for (int i = 0; ss[i]; i++)
		{
			tmp = (int)ss[i];
			for (int j = i; ss[j]; j++)
			{
				if (i == j)
					continue;
				else if (tmp == ss[j])
					clean_exit(d, 1, 2);
			}
		}
	}
}

static void	reading_s_box(t_AFKZ *d, t_sbox *s, char **s_box)
{
	char **tmp;
	
	tmp = NULL;

	if (my_strlen_2d(s_box) != 4)
	{
		free_2d_array(s_box);
		clean_exit(d, 1,1);
	}
	for (int i = 0; s_box[i]; i++)
	{
		tmp = my_split(s_box[i], '\t');
		if (my_strlen_2d(tmp) != 4)
		{
			free_2d_array(tmp);
			free_2d_array(s_box);
			clean_exit(d, 1,1);
		}
		s->s_box[i] = my_strdup("1234");
		for (int j = 0; tmp[j]; j++)
		{
			if (my_isdigit(tmp[j]) == 0)
			{
				free_2d_array(tmp);
				free_2d_array(s_box);
				clean_exit(d, 1, 4);
			}
			s->s_box[i][j] = my_atoi(tmp[j]);
			validate_value(d, tmp, s->s_box[i][j], 1);
		}
		free_2d_array(tmp);
	}

}

void	reading_p_box(t_AFKZ *d, t_pTable *p, char **p_box, int bx_num)
{
	char **tmp = NULL;
	if (bx_num == 1)
	{
		if (my_strlen_2d(p_box) != 5)
		{
			free_2d_array(p_box);
			clean_exit(d, 1,1);
		}
		for (int i = 0; p_box[i]; i++)
		{
			tmp = my_split(p_box[i], '\t');
			if (my_strlen_2d(tmp) != 8)
			{
				free_2d_array(tmp);
				free_2d_array(p_box);
				clean_exit(d, 1,1);
			}
			p->key_pTable[i] = my_strdup("12345678");
			for (int j = 0; tmp[j]; j++)
			{
				if (my_isdigit(tmp[j]) == 0)
				{
					free_2d_array(tmp);
					free_2d_array(p_box);
					clean_exit(d, 1, 4);
				}
				p->key_pTable[i][j] = my_atoi(tmp[j]);
				validate_value(d, tmp, p->key_pTable[i][j], 2);
			}
			free_2d_array(tmp);	
		}	
	}
	else if (bx_num == 2)
	{
		if (my_strlen_2d(p_box) != 1)
		{
			free_2d_array(p_box);
			clean_exit(d, 1,1);			
		}
		tmp = my_split(p_box[0], '\t');
		for (int j = 0; tmp[j]; j++)
		{
			if (my_isdigit(tmp[j]) == 0)
			{
				free_2d_array(tmp);
				free_2d_array(p_box);
				clean_exit(d, 1, 4);
			}
			p->text_pTable[j] = my_atoi(tmp[j]);
			validate_value(d, tmp, p->text_pTable[j], 3);
		}
		free_2d_array(tmp);
	}
}


static void	reading_files_help(t_AFKZ *d, t_sbox *s, char *file_name)
{
	int		fd;
	char	*line;
	char	**tmp_sBox;
	// static int i;

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
	if (strcmp(file_name, "tables/p_box1.DES") == 0)
	{
		reading_p_box(d, d->pTables, tmp_sBox, 1);
		validate_sBox(d, d->pTables->key_pTable, NULL, 1);
		// print_Box(d->pTables->key_pTable, 1);
	}
	else if (strcmp(file_name, "tables/p_box2.DES") == 0)
	{
		reading_p_box(d, d->pTables, tmp_sBox, 2);
		validate_sBox(d, NULL, d->pTables->text_pTable, 2);
		creating_inverse_p(d->pTables);
		// print_Box(&d->pTables->text_pTable, 2);
	}
	else
	{
		reading_s_box(d, s, tmp_sBox);
		validate_sBox(d, s->s_box, NULL, 1);
		// print_Box(s->s_box, 1);
		creating_inverse(s);
	}
	// printf("file [%d][%s]\n", i++, file_name);
	free_2d_array(tmp_sBox);
	close(fd);
}

void	reading_files(t_AFKZ *d)
{
	allocating_all(d);
	for (int i = 0; i < 12; i++)
		reading_files_help(d, &d->sBoxs[i], d->files_name[i]);
}