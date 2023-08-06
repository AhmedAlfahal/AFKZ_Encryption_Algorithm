#ifndef DES_H
#define DES_H

#include "./get_next_line/get_next_line.h"
#include "./my_library/my_lib.h"
#include "fcntl.h"

typedef struct s_pTable
{
	char	**text_pTable;
	char	**key_pTable;
}	t_pTable;

typedef struct s_sbox
{
	char **s_box;
	char **iS_box;
}	t_sbox;


typedef struct s_keys 
{
	char *master;
	char **sub_keys;
}	t_keys;

typedef struct s_round
{
	char	**blocks_before;
	int		round_numebr;
	int		s_box1;
	int		s_box2;
	char	**blocks_after;
}	t_round;

typedef struct s_DES
{
	t_sbox		s_boxs;
	t_keys		*keys;
	t_round		*rounds;
	t_pTable	pTables;
	char		*plain;
	char		*cypher;
}	t_DES;

void	txtBin2int(t_DES *d, char *txt);
void	closing_and_freeing(int fd, char *line, int ext);

#endif