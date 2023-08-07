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
		free_2d_array(d->sBoxs[i].s_box);
		free(d->sBoxs[i].iS_box);
	}
	free_2d_array(d->files_name);
	free(d->sBoxs);
}

void	clean_exit(t_DES *d,int ex, int msg)
{
	free_all(d);
	if (msg == 0)
		write(1, "Thanks for using our Algorithm\n", 32);
	else if (msg == 1)
		write(2, "sBox size is not 4\n", 20);
	else if (msg == 2)
		write(2, "Duplicate in sBox\n", 19);
	else if (msg == 3)
		write(2, "sBox Value range from [0] - [15]\n", 34);
	else if (msg == 4)
		write(2, "sBox has value which is not digit\n", 35);
	if (ex == 1)
		exit (ex);
}

static int	val(t_DES *d, char **tmp, const char *va, int n)
{
	long	res;

	res = 0;
	while (va[n] == '0' && va[n] != '\0')
		n++;
	while (va[n] != '\0' && va[n] >= '0' && va[n] <= '9')
	{
		res = (res * 10) + (va[n] - '0');
			n++;
		if (res > 15 || res < 0)
		{
			free_2d_array(tmp);
			clean_exit(d, 1, 3);
		}
	}
	return (res);
}

int	my_atoi(t_DES *d, char **tmp, const char *str)
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
	res = val (d, tmp, str, i);
	return (res * sgn);
}