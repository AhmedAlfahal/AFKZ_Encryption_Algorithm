#include "../AFKZ.h"

unsigned char prem_txtt(t_pTable *p, unsigned char c)
{
	unsigned char tmp = 0;
	unsigned char tt = c;
	for (int j = 0; j < 8; j++)
	{
		tmp |= (getting_bit(tt, (int)p->text_ipTable[j]) << j);
		tt = c;
	}
	return (tmp);
}

void	roundss(t_pTable *p, t_DES *d, t_round *r)
{
	unsigned char c = 0;
	for (int i = 0; r->blocks_before[i] && r->blocks_after[i]; i++)
	{
		c = r->blocks_after[i][0];
		c = c ^ d->keys.sub_keys[r->round_numebr][0];
		c = s_boxing(d->sBoxs[r->s_box2].iS_box, d->sBoxs[r->s_box1].iS_box, c);
		c = prem_txtt(p,  c);
		r->blocks_before[i][0] = c;
	}
	printf("round	[%d]	", r->round_numebr);
	for (int i = 0; d->plain[i]; i++)
	{
		printBinary(r->blocks_after[i][0]);
		printf("	");
	}
	printf("\n");
}

char	**dupper_2d(char **source)
{
	int	i;
	char **tmp = NULL;

	i = my_strlen_2d(source);
	tmp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (source[i])
	{
		tmp[i] = my_strdup(source[i]);
		i++;
	}
	tmp[i]= NULL;
	return (tmp);
}

void	decrypt(t_DES *d)
{
	for (int roundsss = 4; roundsss >= 0; roundsss--)
	{
		if (roundsss != 4)
		{
			free_2d_array(d->rounds[roundsss].blocks_after);
			d->rounds[roundsss].blocks_after = dupper_2d(d->rounds[roundsss + 1].blocks_before);
		}
		roundss(d->pTables, d, &d->rounds[roundsss]);
	}
	for (int i = 0; d->rounds[0].blocks_before[i]; i++)
		printf("[%c]", d->rounds[0].blocks_before[i][0]);
}