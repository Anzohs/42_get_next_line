#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	char	*str;

	if (fd < 0|| BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	ft_create_list(&list, fd);
	if(!list)
		return (NULL);
	printf("%s main \n",list->content);
	str = ft_get_string(list);
	ft_clean_list(&list);
	return (str);
}