/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:40:09 by hladeiro          #+#    #+#             */
/*   Updated: 2024/05/07 22:34:59 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	ft_add_str(list,fd);
	str = ft_string(&list);
	free_tlist(list);
	return (str);
}
