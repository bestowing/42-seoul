/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:17:53 by chelee            #+#    #+#             */
/*   Updated: 2021/02/11 16:00:55 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_newline(char *buffer, int start, int size)
{
	if (buffer == NULL)
		return (-1);
	while (start < size)
	{
		if (buffer[start] == '\n')
			return (start);
		start++;
	}
	return (-1);
}

static int	buff_to_line(char **line, char *buffer, int idx, int len)
{
	char	*tmp;
	int		i;
	int		line_size;

	line_size = ft_strlen(*line);
	if (!(tmp = malloc(line_size + len - idx + 1)))
		return (ERROR);
	i = -1;
	while (++i < line_size)
		tmp[i] = (*line)[i];
	if (*line != NULL)
		free(*line);
	i = -1;
	len -= idx;
	while (++i < len)
		tmp[i + line_size] = buffer[idx + i];
	tmp[line_size + len] = 0;
	*line = tmp;
	return (SUCCESS);
}

static int	update_buffer(int fd, char **buffer, t_content *content)
{
	int	flag;

	if (content->buff != NULL)
		free(content->buff);
	content->buff = NULL;
	content->index = 0;
	content->len = 0;
	if (!(*buffer = malloc(BUFFER_SIZE)))
		return (handle_error("failed to allocate memory"));
	flag = read(fd, *buffer, BUFFER_SIZE);
	if (flag == ERROR || flag == 0)
	{
		free(*buffer);
		if (flag == ERROR)
			return (handle_error("failed to read the file"));
	}
	else
	{
		content->buff = *buffer;
		content->len = flag;
	}
	return (flag);
}

int			get_next_line(int fd, char **line)
{
	static t_content	content;
	char				*buffer;
	int					idx;
	int					flag;

	*line = NULL;
	buffer = content.buff;
	while ((idx = find_newline(buffer, content.index, content.len)) == -1)
	{
		if (buff_to_line(line, buffer, content.index, content.len) == ERROR)
			return (handle_error("failed to allocate memory"));
		if ((flag = update_buffer(fd, &buffer, &content)) == ERROR)
			return (ERROR);
		else if (flag == 0)
			return (0);
	}
	if ((buff_to_line(line, buffer, content.index, idx)) == ERROR)
		return (handle_error("failed to allocate memory"));
	content.index = idx + 1;
	return (TRUE);
}
