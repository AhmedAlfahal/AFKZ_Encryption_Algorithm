#include "../AFKZ.h"

void	roundss(t_pTable *p, t_AFKZ *d, t_round *r)
{
	unsigned char c = 0;
	for (int i = 0; r->blocks_before[i] && r->blocks_after[i]; i++)
	{
		c = r->blocks_after[i][0];
		c = c ^ d->keys.sub_keys[r->round_numebr][0];
		c = s_boxing(d->sBoxs[r->s_box1].iS_box, d->sBoxs[r->s_box2].iS_box, c);
		c = prem_txt(p,  c, 2);
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

void	decrypt(t_AFKZ *d)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; d->rounds[i].blocks_before[j]; j++)
			my_bzero(d->rounds[i].blocks_before[j], my_strlen(d->rounds[i].blocks_before[j]));
		for (int j = 0; d->rounds[i].blocks_after[j]; j++)
			my_bzero(d->rounds[i].blocks_after[j], my_strlen(d->rounds[i].blocks_after[j]));
	}
	for (int j = 0; d->rounds[4].blocks_before[j]; j++)
		my_bzero(d->rounds[4].blocks_before[j], my_strlen(d->rounds[4].blocks_before[j]));
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