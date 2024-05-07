/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:47:29 by hladeiro          #+#    #+#             */
/*   Updated: 2024/05/07 22:34:55 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE  10


# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	char	*content;
	struct s_list	*next;
}			t_list;

char *get_next_line(int fd);
char *copy_str(char *p, t_list *list, int num);
char  *ft_string(t_list **list);
int	ft_length(char *content);
t_list	*ft_list_last(t_list *list);
void	ft_add_back(t_list **list, t_list *lista);
int ft_brk(char *p);
void    ft_add_str(t_list *list, int fd);
t_list  *ft_new_list(char *content);
void	free_tlist(t_list *list);

#endif