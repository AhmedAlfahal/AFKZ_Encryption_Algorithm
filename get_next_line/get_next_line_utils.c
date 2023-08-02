#include "get_next_line.h"

char	*cut(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	else
		sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[start] != '\0' && i < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

int	line_len(char *s)
{
	int		i;
	int		ln;

	if (!s)
		return (0);
	i = 0;
	ln = len(s);
	while (i < ln)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	len(char *s)
{
	int	i;

	i = 0;
	if (!s || *s == '\0')
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*join(char *s1, char *s2)
{
	char	*dup;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 && !s2)
		return (s1);
	if (!s1 && s2)
		return (s2);
	if (!s1 && !s2)
		return (NULL);
	dup = malloc(sizeof(char *) * (len(s1) + len(s2) + 1));
	if (!dup)
		return (NULL);
	while (s1[i] != '\0')
		dup[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		dup[i++] = s2[j++];
	dup[i] = '\0';
	return (free(s1), free(s2), dup);
}

void	add_front(t_list **lst, t_list *neww)
{
	if (!lst || !neww)
		return ;
	neww->next = (*lst)->next;
	*lst = neww;
}
