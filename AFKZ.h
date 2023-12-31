#ifndef AFKZ_H
#define AFKZ_H

#include "./get_next_line/get_next_line.h"
#include "fcntl.h"
#include <stdlib.h>
#include "my_library/my_lib.h"
#include <stdio.h>

typedef struct s_pTable
{
	char	*text_pTable;
	char	*text_ipTable;
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

typedef struct s_AFKZ
{
	t_sbox		*sBoxs;
	t_keys		keys;
	t_round		*rounds;
	t_pTable	*pTables;
	char		*plain;
	char		*cypher;
	char		**files_name;
}	t_AFKZ;

void	closing_and_freeing(int fd, char *line, int ext);
void	reading_files(t_AFKZ *d);
void	free_2d_array(char **s);
void	clean_exit(t_AFKZ *d,int ex, int msg);
int		my_atoi(const char *str);
void	print_2d_array(char **d);
void	print_Box(char **sBox, int msg);
void	creating_inverse(t_sbox *s);
void	creating_inverse_p(t_pTable *p);
void	reading_keys(t_AFKZ *d, char *key);
void 	printBinary(unsigned char v);
void	encrypt(t_AFKZ *d);
void	decrypt(t_AFKZ *d);
char	**dupper_2d(char **source);
unsigned int	getting_bit(unsigned char c, int n);
unsigned int	new_i(unsigned int s);
unsigned int	new_j(unsigned int s);
unsigned int 	get_left(unsigned int s);
unsigned int	get_right(unsigned int s);
unsigned char	s_boxing(char **sl, char **sr, unsigned char c);
unsigned char prem_txt(t_pTable *p, unsigned char c, int p_i);

#endif