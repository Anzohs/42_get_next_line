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
	data->i = 0;
	while (data->line && data->line[data->i])
		str[data->j++] = data->line[data->i++];
	data->i = 0;
	while ((size_t)data->j < data->len)
		str[data->j++] = s[data->i++];
	str[data->j] = 0;
	ft_clean_str(s, data);
	free(data->line);
	data->line = str;
}
