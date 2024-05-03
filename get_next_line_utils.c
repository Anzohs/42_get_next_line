/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:00:49 by hladeiro          #+#    #+#             */
/*   Updated: 2024/05/03 20:17:25 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list  *ft_new_list(char *content)
{
    t_list  *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return new;

}

void	free_tlist(t_list	*list)
{
	t_list	*t_next;
	while(list-> next)
	{	
		t_next = list->next;
		free(list);
		list =  t_next;
	}
}