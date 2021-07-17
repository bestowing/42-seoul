/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@42seoul.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:14:58 by chelee            #+#    #+#             */
/*   Updated: 2020/10/08 17:11:04 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	my_strlen(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		buff_to_line(char **line, char *buffer, size_t idx, size_t len)
{
	char	*tmp;
	size_t	i;
	size_t	line_size;

	i = 0;
	line_size = my_strlen(*line);
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

int		is_in_newline(char *buffer, size_t start, size_t size)
{
	size_t	i;

	if (buffer == NULL)
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

size_t	my_strchr(char *buffer, size_t start, size_t size)
{
	size_t	i;

	i = start;
	while (i < size)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
