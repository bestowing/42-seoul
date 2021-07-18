/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 02:55:19 by chelee            #+#    #+#             */
/*   Updated: 2021/06/25 03:03:46 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	update_buffer(int fd, char **buffer, t_content *content)
{
	int	flag;

	if (content->buff != NULL)
		free(content->buff);
	content->buff = NULL;
	content->index = 0;
	content->len = 0;
	if ((*buffer = malloc(BUFFER_SIZE)) == 0)
		return (-1);
	flag = read(fd, *buffer, BUFFER_SIZE);
	if (flag == -1 || flag == 0)
		free(*buffer);
	else
	{
		content->buff = *buffer;
		content->len = flag;
	}
	return (flag);
}

static int	buff_to_line(char **line, char *buffer, int idx, int len)
{
	char	*tmp;
	int		i;
	int		line_size;

	i = 0;
	line_size = ft_strlen(*line);
	if ((tmp = malloc(line_size + len - idx + 1)) == 0)
		return (0);
	while (i < line_size)
	{
		tmp[i] = (*line)[i];
		i++;
	}
	i = 0;
	while (i < (len - idx))
	{
		tmp[i + line_size] = buffer[idx + i];
		i++;
	}
	tmp[line_size + len - idx] = 0;
	if (*line != NULL)
		free(*line);
	*line = tmp;
	return (1);
}

static int	is_in_newline(char *buffer, int start, int size)
{
	int	i;

	if (!buffer)
		return (0);
	i = start;
	while (i < size)
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	my_strchr(char *buffer, int start, int size)
{
	int	i;

	i = start;
	while (i < size)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static t_content	content[1024];
	int					idx;
	char				*buffer;
	int					flag;

	*line = NULL;
	buffer = content[fd].buff;
	while (!(is_in_newline(buffer, content[fd].index, content[fd].len)))
	{
		if (!(buff_to_line(line, buffer, content[fd].index, content[fd].len)))
			return (-1);
		flag = update_buffer(fd, &buffer, content + fd);
		if (flag <= 0)
			return (flag);
	}
	idx = my_strchr(buffer, content[fd].index, content[fd].len);
	if ((buff_to_line(line, buffer, content[fd].index, idx)) == 0)
		return (-1);
	content[fd].index = idx + 1;
	return (1);
}
