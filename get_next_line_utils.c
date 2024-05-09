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
	char	*p;
	t_list	*last;

	if (!list)
		return (0);
	last = ft_lst_last(list);
	if (!last)
		return (0);
	p = last->content;
	while (*p && *p != '\n')
		p++;
	if (*p == '\n')
		return (1);
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

	last = ft_lst_last(*list);
	new = malloc(sizeof(t_list));
	new->content = str;
	new->next = NULL;
	printf("%s", new->content);
	if (!last)
		*list = new;
	else
		last->next = new;
}

static char	*ft_get_clean_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if(str[i] == '\n')
	{
		i++;
		return ((str + i));
	}
	return (NULL);
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
		free(str);
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
	printf("testing string %s \n", str);
	return (str);
}

	
void	ft_clean_list(t_list **list)
{
	t_list	*new;
	t_list	*t;
	char	*s;

	new = *list;
	while (new->next)
	{
		t = new->next;
		free(new);
		new = t;
	}
	s = ft_get_clean_string(new->content);
	if (s)
		ft_lstadd_back(list, s);
	free(new);
}