#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*string[BUFFER_SIZE + 1];
	t_data		data;

	if (fd < 0|| BUFFER_SIZE <= 0)
		return (NULL);
	data.n = false;
	while (!data->n)
	{
		data.line = NULL;
		if (!*string)
			data.j = read(fd, string, BUFFER_SIZE);
		if (data.j <= 0)
			return (data.line);
		data.i = 0;
		data.j = 0;
		get_line(string, &data);
	}
	return (data.line);
}
