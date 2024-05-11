/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:29:27 by hladeiro          #+#    #+#             */
/*   Updated: 2024/05/11 20:41:08 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE];
	t_data		data;

	if (fd < 1 || BUFFER_SIZE < 1)
		return (NULL);
	data.n = 0;
	data.line = NULL;
	data.i = 1;
	while (!data.n)
	{
		if (!*str)
			data.i = read(fd, str, BUFFER_SIZE);
		if (data.i < 1)
			return (data.line);
		data.i = 0;
		data.j = 0;
		data.len = 0;
		ft_get_line(str, &data);
	}
	return (data.line);
}
