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
		free_2d_array(d->files_name);
		free_2d_array(d->sBoxs[i].s_box);
	}
	free(d->sBoxs);
}

void	clean_exit(t_DES *d, int ex)
{
	free_all(d);
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
			clean_exit(d, 1);
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