/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@42seoul.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:19:23 by chelee            #+#    #+#             */
/*   Updated: 2020/10/08 17:19:32 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_next_line(int fd, char **line)
{
	if (fd < 0 || fd == STDOUT_FILENO || fd == STDERR_FILENO || fd >= 1024)
		return (-1);
	if (BUFFER_SIZE <= 0)
		return (-1);
	if (line == NULL)
		return (-1);
	*line = NULL;
	return (read_this_line(fd, line));
}

int	read_this_line(int fd, char **line)
{
	static t_content	content[1024];
	size_t				idx;
	char				*buffer;
	int					flag;

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

int	update_buffer(int fd, char **buffer, t_content *content)
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
