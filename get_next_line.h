#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE  1
# endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_data
{
	size_t		j;
	char	*line;
	size_t		i;
	bool		n;
}			t_data;

char	*get_next_line(int fd);

#endif