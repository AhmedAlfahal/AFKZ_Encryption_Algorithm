#ifndef MYL_IB_H
# define MYL_IB_H

# include<stdlib.h>
# include<unistd.h>
# include <stdint.h>

int		my_strlen(const char *s);
void	my_bzero(void *s, size_t n);
char	**my_split(char const *s, char c);
int		my_filecmp(const char *s1, const char *s2, int n);
char	*my_substr(char const *s, unsigned int start, int len);
char	*my_strdup(const char *s1);
int		my_strlen_2d(char **s);
int		my_isdigit(char *s);
char	**dupper_2d(char **source);
#endif
