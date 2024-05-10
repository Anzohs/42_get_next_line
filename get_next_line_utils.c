#include "get_next_line.h"

void	get_line(char *str, t_data *data)
{
	char *read_line;

	while (str[data->i] && str[data->i] != '\n')
		data->i++;
	data->n = str[data->i] == '\n';
	data->j += ((str[data->i] == '\n') + data->i);
	read_line = malloc(data->j + 1);
	if (!read_line)
		return ;
	data->j = 0;
	data->i = 0;
	while (data->line[data->i] && data->line)
		read_line[data->i++] = data->line[data->j++];
	data->j = 0;
	while (str[data->j])
	{
		read_line[data->j] = str[data->j];
		if(str[data->j == '\n'])
		{
			read_line[data->j + 1] = 0;
			free(data->line);
			data->line = read_line;
			return ;
		}
		data->j++;
	}
	free(data->line);
	data->line = read_line; 
}


/* void	get_line(char *buf, t_data	*data)
{
	char	*str;

	while (buf[data->i] && buf[data->i] != '\n')
		data->i++;
	data->size += ((buf[data->i] == '\n') + data->i);
	str = malloc(data->size + 1);
	if (!str)
		return ;
	data->i = 0;
	while (data->line && data->line[data->i])
		str[data->i++] = data->line[data->j++];
	data->j = -1;
	while (buf[data->len]) 
	{
		if (data->j != -1)
			buf[data->j++] = buf[data->len];
		else if (data->j == -1)
			str[data->i++] = buf[data->len];
		if (data->j == -1 && buf[data->len] == '\n')
			data->j = 0;
		buf[data->len++] = '\0';			
	}
	str[data->i] = 0;
	free(data->line);
	data->line = str;
}


char	*get_next_line(int fd)
{
	static char 	buf[BUFFER_SIZE + 1];
	t_data		data;

	if (fd < 0|| BUFFER_SIZE <= 0)
		return (NULL);
	data.line = NULL;
	data.size = 0;
	data.j = 2;
	while (1)
	{
		if (*buf == '\0')
			data.j = read(fd, buf, BUFFER_SIZE);
		if (data.j < 1)
			break;
		data.i = 0;
		data.j = 0;
		data.len = 0;
		get_line(buf, &data);
		if (data.j != -1)
			break;
	}
	
	return (data.line);
} */