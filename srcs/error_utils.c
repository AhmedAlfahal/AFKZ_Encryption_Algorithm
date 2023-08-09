#include "../AFKZ.h"

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

// void	free_all(t_AFKZ *d, int w)
// {
// 	if (w == 2)
// 	{
// 		for (int i = 0; i < 11; i++)
// 		{
// 			free_2d_array(d->sBoxs[i].s_box);
// 			free_2d_array(d->sBoxs[i].iS_box);
// 		}
// 		for (int i = 0; i < 5; i++)
// 		{
// 			free_2d_array(d->rounds[i].blocks_before);
// 			free_2d_array(d->rounds[i].blocks_after);
// 		}
// 		free(d->rounds);
// 	}
// 	free_2d_array(d->keys.sub_keys);
// 	free_2d_array(d->files_name);
// 	free(d->sBoxs);
// 	free_2d_array(d->pTables->key_pTable);
// 	free(d->pTables->text_pTable);
// 	free(d->pTables->text_ipTable);
// 	free(d->pTables);
// }

void	clean_exit(t_AFKZ *d,int ex, int msg)
{
	// free_all(d);
	(void)d;
	if (msg == 0)
		write(1, "Thanks for using our Algorithm\n", 32);
	else if (msg == 1)
		write(2, "sBox size must be 4x4\n", 23);
	else if (msg == 2)
		write(2, "Duplicate in sBox\n", 19);
	else if (msg == 3)
		write(2, "sBox Value range from [0] - [15]\n", 34);
	else if (msg == 4)
		write(2, "Box has value which is not digit\n", 34);
	else if (msg == 5)
		write(2, "pTable for key Value range from [0] - [39]\n", 44);
	else if (msg == 6)
		write(2, "pTable for text Value range from [0] - [7]\n", 44);
	else if (msg == 7)
		write(2, "key size must be only 5 characters\n", 36);
	if (ex == 1)
		exit (ex);
}

static int	val(const char *va, int n)
{
	long	res;

	res = 0;
	while (va[n] == '0' && va[n] != '\0')
		n++;
	while (va[n] != '\0' && va[n] >= '0' && va[n] <= '9')
	{
		res = (res * 10) + (va[n] - '0');
		n++;
	}
	return (res);
}

int	my_atoi(const char *str)
{
	int					i;
	int					sgn;
	long long			res;

	i = 0;
	sgn = 1;
	res = 0;
	while (str[i] == ' ' || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] == '-' || str[i + 1] == '+'))
			return (0);
		else if (str[i] == '-')
				sgn = -1;
			i++;
	}
	res = val (str, i);
	return (res * sgn);
}