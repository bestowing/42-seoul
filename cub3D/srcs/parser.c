/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 03:37:23 by chelee            #+#    #+#             */
/*   Updated: 2021/02/19 11:00:19 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_type(char *line)
{
	int	ret;

	if (line[0] == 'R')
		ret = 0;
	else if (line[0] == 'N' && line[1] == 'O')
		ret = 1;
	else if (line[0] == 'S' && line[1] == 'O')
		ret = 2;
	else if (line[0] == 'W' && line[1] == 'E')
		ret = 3;
	else if (line[0] == 'E' && line[1] == 'A')
		ret = 4;
	else if (line[0] == 'S')
		ret = 5;
	else if (line[0] == 'F')
		ret = 6;
	else if (line[0] == 'C')
		ret = 7;
	else
		ret = ERROR;
	return (ret);
}

static int	check_type(t_game *game, char *line, int *check, int type)
{
	if (type == -1 || check[type])
	{
		free(line);
		if (type == -1)
			return (handle_error("type identifier is undefined."));
		return (handle_error("type identifier is duplicated."));
	}
	check[type] = TRUE;
	if (type == 0)
		return (handle_resolution(game, line));
	else if (type == 1)
		return (handle_texture(game, line, NORTH));
	else if (type == 2)
		return (handle_texture(game, line, SOUTH));
	else if (type == 3)
		return (handle_texture(game, line, WEST));
	else if (type == 4)
		return (handle_texture(game, line, EAST));
	else if (type == 5)
		return (handle_item(game, line));
	else if (type == 6)
		return (handle_color(game, line, TRUE));
	return (handle_color(game, line, FALSE));
}

static int	check_element(int *check, int is_init)
{
	int	i;

	i = -1;
	if (is_init)
	{
		while (++i < 8)
			check[i] = FALSE;
	}
	else
	{
		while (++i < 8)
			if (check[i] == FALSE)
				return (FALSE);
	}
	return (TRUE);
}

static int	parse_elements(t_game *game, int fd)
{
	int		check[8];
	char	*line;
	int		flag;

	check_element(check, TRUE);
	while ((flag = get_next_line(fd, &line)) == TRUE)
	{
		if (line[0] == 0 || !ft_isstr(line))
		{
			free(line);
			continue ;
		}
		if (!(line = ft_strtrim(line)))
			return (handle_error("failed to allocate memory."));
		if (check_type(game, line, check, get_type(line)) == ERROR)
			return (ERROR);
		if (check_element(check, FALSE))
			break ;
	}
	if (flag == ERROR)
		return (handle_error("failed to read file."));
	if (check_element(check, FALSE) == FALSE)
		return (handle_error("type identifier is not found."));
	return (SUCCESS);
}

int			handle_file(t_game *game, char *name)
{
	int	fd;
	int	len;

	len = ft_strlen(name);
	if (len < 4 || name[len - 4] != '.' || name[len - 3] != 'c' ||
		name[len - 2] != 'u' || name[len - 1] != 'b')
		return (handle_error("File name extension is not '.cub'."));
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (handle_strerror());
	if (parse_elements(game, fd) == ERROR)
	{
		close(fd);
		return (ERROR);
	}
	if (parse_map(game, fd) == ERROR)
	{
		close(fd);
		return (ERROR);
	}
	if (close(fd) == -1)
		return (handle_strerror());
	return (SUCCESS);
}
