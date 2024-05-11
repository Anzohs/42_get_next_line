#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
<<<<<<< HEAD
#  define BUFFER_SIZE  1
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_data
{
	char	*line;
    size_t	i;
    int		j;
	size_t	len;
    int		n;
}			t_data;

char	*get_next_line(int fd);
void	ft_get_line(char s[BUFFER_SIZE], t_data *data);
void	ft_clean_str(char s[BUFFER_SIZE], t_data *data);
=======
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
>>>>>>> 0d6023053fccb752bcc89700aa5f18e4e6456668

#endif
