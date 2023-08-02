#ifndef DES_H
#define DES_H

#include "./get_next_line/get_next_line.h"
#include "./my_library/my_lib.h"
#include "fcntl.h"
typedef struct s_DES
{
	int **s_box;
	int **keys;
}	t_DES;

void	txtBin2int(t_DES *d, char *txt);
void	closing_and_freeing(int fd, char *line, int ext);

#endif