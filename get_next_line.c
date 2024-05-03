/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:40:09 by hladeiro          #+#    #+#             */
/*   Updated: 2024/05/03 20:14:07 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(BUFFER_SIZE);
	if(!str)
		return (NULL);
	list = ft_new_list(str);
	if(!list)
		return (NULL);
	read(fd,list->content, BUFFER_SIZE);

	printf("%s", list->content);
	free_tlist(list);
	return (NULL);
}

int	main()
{
	int	fd;
	fd = open("test.txt", O_RDONLY);
	printf("\n");
	get_next_line(fd);
}