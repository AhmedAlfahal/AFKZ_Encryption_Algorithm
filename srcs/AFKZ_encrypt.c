#include "../AFKZ.h"

static unsigned char reverseBits(unsigned char num) {
    int numOfBits = 8;
    int reversed = 0;

    for (int i = 0; i < numOfBits; i++) {
        if ((num & (1 << i)) != 0) {
            reversed |= (1 << ((numOfBits - 1) - i));
        }
    }
    return reversed;
}

unsigned char prem_txt(t_pTable *p, unsigned char c)
{
	unsigned char tmp = 0;
	unsigned char tt = c;
	for (int j = 0; j < 8; j++)
	{
		tmp |= (getting_bit(tt, (int)p->text_pTable[j]) << j);
		tt = c;
	}
	return (tmp);
}

void	rounds(t_pTable *p, t_DES *d, t_round *r)
{
	unsigned char c = 0;
	// printf("round	[%d]	B	", r->round_numebr);
	// for (int i = 0; d->plain[i]; i++)
	// {
	// 	printBinary(r->blocks_before[i][0]);
	// 	printf("	");
	// }
	// printf("\n");
	for (int i = 0; r->blocks_before[i]; i++)
	{
		c = prem_txt(p,  r->blocks_before[i][0]);
		c = s_boxing(d->sBoxs[r->s_box1].s_box, d->sBoxs[r->s_box2].s_box, c);
		c = c ^ d->keys.sub_keys[r->round_numebr][0];
		r->blocks_after[i][0] = c;
	}
	printf("round	[%d]	", r->round_numebr);
	for (int i = 0; d->plain[i]; i++)
	{
		printBinary(r->blocks_after[i][0]);
		printf("	");
	}
	printf("\n");
}

void	dividing_blocks(t_DES *d)
{
	d->rounds = malloc(sizeof(t_round) * 6);
	my_bzero(d->rounds, sizeof(t_round) * 6);
	for (int i = 0; i < 5; i++)
	{
		d->rounds[i].blocks_before = malloc(sizeof(char * ) * (my_strlen(d->plain) + 1));
		d->rounds[i].blocks_after = malloc(sizeof(char * ) * (my_strlen(d->plain) + 1));
		my_bzero(d->rounds[i].blocks_before, sizeof(char * ) * (my_strlen(d->plain) + 1));
		my_bzero(d->rounds[i].blocks_after, sizeof(char * ) * (my_strlen(d->plain) + 1));
		d->rounds[i].round_numebr = i;
		d->rounds[i].s_box1 = (unsigned int)d->keys.sub_keys[i][0] % 10;
		d->rounds[i].s_box2 = reverseBits(d->keys.sub_keys[i][0]) % 10;
	}
	for (int roundss = 0; roundss < 5; roundss++)
	{
		for (int i = 0; i < d->plain[i]; i++)
		{
			d->rounds[roundss].blocks_before[i] = my_strdup("0");
			// my_bzero(d->rounds[roundss].blocks_before[i], my_strlen(d->rounds[roundss].blocks_before[i]));
			d->rounds[roundss].blocks_after[i] = my_strdup("0");
			// my_bzero(d->rounds[roundss].blocks_after[i], my_strlen(d->rounds[roundss].blocks_before[i]));
		}
		if (roundss == 0)
		{
			for (int i = 0; d->plain[i]; i++)
				d->rounds[roundss].blocks_before[i][0] = d->plain[i];
		}
		else
		{
			free_2d_array(d->rounds[roundss].blocks_before);
			d->rounds[roundss].blocks_before = dupper_2d(d->rounds[roundss - 1].blocks_after);
		}
		rounds(d->pTables, d, &d->rounds[roundss]);
	}
	for (int i = 0; d->rounds[4].blocks_after[i]; i++)
		printf("[%c]", d->rounds[0].blocks_after[i][0]);
	printf("\n");
}
