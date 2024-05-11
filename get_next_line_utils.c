 #include "get_next_line.h"

void	ft_clean_str(char s[BUFFER_SIZE], t_data *data)
{
	data->len = 0;
	data->i = 0;
	while (s[data->len] && s[data->len] != '\n')
		data->len++;
	while (s[data->i])
	{
		if (s[data->len] == '\n')
			s[data->len++] = 0;
		s[data->i++] = s[data->len++];
	}
}

void	ft_get_line(char s[BUFFER_SIZE], t_data *data)
{
	char	*str;

	if (!s)
		return;
	while (s[data->len] && s[data->len] != '\n')
		data->len++;
	if (s[data->len] == '\n')
	{
		data->len++;
		data->n = 1;
	}
	while (data->line && data->line[data->i])
		data->i++;
	data->len += data->i;
	str = malloc((data->len) + 1);
	if (!str)
		return ;
	data->j = 0;
	data->i = 0;
	while (data->line[data->j])
		str[data->i++] = data->line[data->j++];
	data->j = 0;
	while (s[data->j])
	{
		s[data->j] = str[data->i];
		if(str[data->i== '\n'])
		{
			str[data->i + 1] = 0;
			free(data->line);
			data->line = str;
			return ;
		}
		data->j++;
	}
	free(data->line);
	data->line = str;
}


/* void	get_line(char *buf, t_data	*data)
{
	char	*str;

	while (buf[data->i] && buf[data->i] != '\n')
		data->i++;
	data->size += ((buf[data->i] == '\n') + data->i);
	str = malloc(data->size + 1);
>>>>>>> 0d6023053fccb752bcc89700aa5f18e4e6456668
	if (!str)
		return ;
	data->i = 0;
	while (data->line && data->line[data->i])
<<<<<<< HEAD
		str[data->j++] = data->line[data->i++];
	data->i = 0;
	while ((size_t)data->j < data->len)
		str[data->j++] = s[data->i++];
	str[data->j] = 0;
	ft_clean_str(s, data);
	free(data->line);
	data->line = str;
}
=======
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
