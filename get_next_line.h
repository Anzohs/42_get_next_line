/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:30:14 by hladeiro          #+#    #+#             */
/*   Updated: 2024/05/11 21:02:26 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_data
{
	size_t	i;
	size_t	len;
	char	*line;
	int		j;
	int		n;
}			t_data;

char	*get_next_line(int fd);
void	ft_get_line(char s[BUFFER_SIZE], t_data *data);
void	ft_clean_str(char s[BUFFER_SIZE], t_data *data);

#endif
