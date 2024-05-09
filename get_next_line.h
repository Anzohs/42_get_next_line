#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE  10
# endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_list
{
	char	*content;
	struct s_list	*next;	
}			t_list;

char	*get_next_line(int fd);
char	*ft_get_string(t_list *list);
void	ft_create_list(t_list **list, int fd);
void	ft_clean_list(t_list **list);

#endif