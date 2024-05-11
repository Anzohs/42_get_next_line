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
	data.len = 0;
	while (!data.n)
	{
		if (!*str)
			data.i = read(fd, str, BUFFER_SIZE);
		if (data.i < 1)
			return (NULL);
		data.i = 0;
		data.j = 0;
		data.len = 0;
		ft_get_line(str, &data);
	}
	data.n = 0;
	return (data.line);
}
