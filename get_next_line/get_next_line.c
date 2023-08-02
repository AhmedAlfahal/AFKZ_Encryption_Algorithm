#include"get_next_line.h"
#include<stdio.h>

t_list	*lst_new(char *content)
{
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(t_list) * 1);
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	add_back(t_list **lst, char *content)
{
	t_list	*tmp;
	t_list	*new_node;

	if (!content)
		return ;
	new_node = lst_new(content);
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

int	ft_ahmed(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i <= n && a[i] == b[i] && a[i] != '\0' && b[i] != '\0')
	{
		if (i == n - 1)
		{
			return (0);
		}
		i++;
	}
	return (a[i] - b[i]);
}

char	*read_lst(t_list **lst)
{
	char	*result;
	t_list	*node;
	char	*tmp;

	if (!*lst)
		return (NULL);
	if (ft_ahmed((*lst)->content, "\0", \
		len((*lst)->content)) == 0 && (*lst)->next == NULL)
		return (free((*lst)->content), free(*lst), NULL);
	result = NULL;
	while ((*lst) != NULL)
	{
		node = (*lst);
		tmp = node->content;
		if (line_len(tmp) != -1)
		{
			result = join(result, cut(tmp, 0, line_len(tmp)));
			(*lst) = (*lst)->next;
			return (free(tmp), free(node), result);
		}
		result = join(result, tmp);
		(*lst) = (*lst)->next;
		free(node);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char			*buf;
	static t_list	*list;
	int				read_return;
	int				line_detect;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 10240 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	read_return = read(fd, buf, BUFFER_SIZE);
	if (read_return == -1)
		return (free(buf), NULL);
	buf[read_return] = '\0';
	line_detect = line_len(buf);
	while (read_return > 0)
	{
		add_back(&list, cut(buf, 0, read_return));
		if (line_detect != -1)
			return (free(buf), read_lst(&list));
		read_return = read(fd, buf, BUFFER_SIZE);
		buf[read_return] = '\0';
		line_detect = line_len(buf);
	}
	return (free(buf), read_lst(&list));
}
