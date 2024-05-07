
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:00:49 by hladeiro          #+#    #+#             */
/*   Updated: 2024/05/07 18:25:56 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char copy_str(char *p, t_list *list, int num)
{
	int	i;
	int	j;
	i = 0;
	while (i < num)
	{
		while (list->content[j])
			p[i++] = list->content[j++]
		j = 0;
	}
	p[i] = 0;
	return (p);
}


char  ft_string(t_list **list)
{
	t_list *new;
	int	i;
	int z;
	char *str;

	new = *list;
	i = 0;
	z = 0;
	while (new->next)
	{
		i += (new->content);
		new = new->next;
	}
	str = malloc(i+1);
	if (!str)
		return (NULL);
	new = list;
	str
}

int	ft_length(char *content)
{
	int	i;

	i = 0;
	while (content[i] && content[i] != '/n')
		i++;
	return (i);
}


void	ft_list_last(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		lst = list->next;
	return (lst);
	
}

void	ft_add_back(t_list **list, t_list *lista)
{
	t_list	*new;

	new = ft_list_last(*list);
	if (!*list)
		*list = lista;
	else
		mew->next = lista;

}

int ft_brk(char *p)
{
    int i;

	if (!p)
		return (0);
    while (str[i] != '\n' && str[i])
            i++;
    return(str[i] == '\n');
}

void    ft_add_str(static t_list *list, int fd);
{
    char    *str;
    int	i;
	t_list	*new;

	new = list;
    while(!ft_brk(new->content))
    {
        str = malloc(BUFFER_SIZE + 1)
		if (!str)
		{
			free_tlist(list);
			return; 
		}
		i = read(fd, str, BUFFER_SIZE);
		str[i] = 0;
		if(!new)
			ft_add_back(&list, ft_new_list(str))
			new = ft_last(&list);
		else
		{	
			ft_add_back(&list, ft_new_list(str))
			new = ft_list_last(&list);
		}
		free(str);
    }
}

t_list  *ft_new_list(char *content)
{
    t_list  *new;
    
    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->next = NULL;
    return new;
}

void	free_tlist(static t_list **list)
{
	t_list	*t_next;

	while(*list-> next)
	{	
		t_next = *list->next;
		free(*list);
		list =  t_next;
	}
	free(*list);
}