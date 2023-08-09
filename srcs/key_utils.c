#include "../AFKZ.h"

static int	getting_bitt(char *key, int n)
{
	char *tmp = my_strdup(key);
	int index = n / 8;
	int shifts = n % 8;
	int bit = ((unsigned char)tmp[index] >> (shifts)) & 1;
	free(tmp);
	return (bit);
}


void	reading_keys(t_DES *d, char *key)
{
	if (my_strlen(key) != 5)
		clean_exit(d, 1, 7);
	for (int i = 0; i < 5; i++)
	{
		d->keys.sub_keys[i] = my_strdup("1");
		my_bzero(d->keys.sub_keys[i] ,sizeof(char) * 2);
	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 8; j++)
			d->keys.sub_keys[i][0] |= (getting_bitt(key, d->pTables->key_pTable[i][j]) << j);
}