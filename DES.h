#ifndef DES_H
#define DES_H

#include "./get_next_line/get_next_line.h"
#include "fcntl.h"
#include <stdlib.h>
#include "my_library/my_lib.h"
#include <stdio.h>

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
	t_sbox		*sBoxs;
	t_keys		keys;
	t_round		*rounds;
	t_pTable	pTables;
	char		*plain;
	char		*cypher;
	char		**files_name;
}	t_DES;

void	closing_and_freeing(int fd, char *line, int ext);
void	reading_files(t_DES *d);
void	free_2d_array(char **s);
void	clean_exit(t_DES *d, int ex);
int		my_atoi(t_DES *d, char **tmp, const char *str);

#endif