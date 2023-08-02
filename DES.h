#ifndef DES_H
#define DES_H

#include "./get_next_line/get_next_line.h"

typedef struct s_DES
{
	int **s_box;
	int **keys;
}	t_DES;

void	txtBin2int(t_DES *d);

#endif