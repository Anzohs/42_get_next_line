#include "get_next_line.h"

static t_list	*ft_lst_last(t_list *lst);

static void	ft_copy_str(t_list *list, char *s)
{
	int	i;
	int	j;

	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				s[j++] = '\n';
				s[j] = '\0';
				return ;
			}
			s[j] = list->content[i];
			j++;
			i++;
		}
		list = list->next;
	}
	s[j] = '\0';
}

static	int	ft_str_len(t_list *list)
{
	t_list	*temp;
	int	i;
	int	len;

	temp = list;
	if (!list)
		return (0);
	len = 0;
	while (temp)
	{
		i = 0;
		while (temp->content[i])
		{
			if (temp->content[i] == '\n')
				return(++len);
			i++;
			len++;
		}
		temp = temp->next;
	}
	return (len);
}

static int	ft_space(t_list *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list)
	{
		while (list->content[i] && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
		i = 0;
	}
	return (0);
}

static t_list	*ft_lst_last(t_list *lst)
{
	if(!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static void	ft_lstadd_back(t_list **list, char	*str)
{
	t_list	*last;
	t_list	*new;

	if (!str)
		return ;
	last = ft_lst_last(*list);
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	if (!last)
		*list = new;
	else
		last->next = new;
	new->content = str;
	new->next = NULL;
}

static char	*ft_get_clean_string(char *str)
{
	int	i;
	int	j;
	char	*s;

	i = 0;
	j = 0;
	if(!str)
		return (NULL);
	s = malloc(BUFFER_SIZE + 1);
	if (!s)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	while(str[i] && str[++i])
		s[j++] = str[i];
	s[j] = 0;
	return (s);	
}

void	ft_create_list(t_list **list, int fd)
{
	char	*str;
	int	i;

	while (!ft_space(*list))
	{
		str = malloc(BUFFER_SIZE + 1);
		if (!str)
			return ;
		i = read(fd, str, BUFFER_SIZE);
		if (!i)
		{
			free(str);
			return ;
		}
		str[i] = 0;
		ft_lstadd_back(list, str);		
	}
}

char	*ft_get_string(t_list *list)
{
	char	*str;

	if(!list)
		return (NULL);
	str = malloc(ft_str_len(list) + 1);
	if (!str)
		return (NULL);
	ft_copy_str(list, str);
	return (str);
}

	
void	ft_clean_list(t_list **list)
{
	t_list	*t;
	char	*p;

	if (!*list)
		return ;
	while ((*list)->next)
	{
		t = (*list)->next;
		free((*list)->content);
		free(*(list));
		*list = t;
	}
	p = ft_get_clean_string((*list)->content);
	if (!p)
	{
		free((*list)->content);
		free(*list);
		return ;
	}
	ft_lstadd_back(list, p);
	if ((*list)->next)
	{
		t = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = t;
	}

}