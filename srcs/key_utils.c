#include "../AFKZ.h"

void	reading_keys(t_DES *d, char *key)
{
	if (my_strlen(key) != 5)
		clean_exit(d, 1, 3);
}