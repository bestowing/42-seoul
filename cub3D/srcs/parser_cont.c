/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 05:08:45 by chelee            #+#    #+#             */
/*   Updated: 2021/02/23 17:30:49 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ctoi(t_game *game, char c, int row, int col)
{
	if (c >= '0' && c <= '2')
		return (c - '0');
	else if (c == ' ')
		return (0);
	if (game->player.pos_x != -1.0 || game->player.pos_y != -1.0)
		return (handle_error("player position is duplicated."));
	game->player.pos_x = col;
	game->player.pos_y = row;
	if (c == 'W' || c == 'E')
	{
		game->player.dir_y = 0;
		if (c == 'W')
			game->player.dir_x = -1;
		else
			game->player.dir_x = +1;
	}
	else
	{
		game->player.dir_x = 0;
		if (c == 'N')
			game->player.dir_y = -1;
		else
			game->player.dir_y = +1;
	}
	return (0);
}

static int	get_map(t_game *game, char *map, int i, int j)
{
	int	**m;
	int	idx;

	if (!(m = allo_map(game->m_height, game->m_width)))
		return (handle_error("failed to allocate memory"));
	idx = 0;
	while (++i < game->m_height)
	{
		j = -1;
		while (++j < game->m_width)
		{
			if (map[idx] != '\n' && map[idx] != 0)
				m[i][j] = ctoi(game, map[idx++], i, j);
			if (m[i][j] == ERROR)
			{
				free(m);
				return (ERROR);
			}
			else if (m[i][j] == 2)
				game->item_size += 1;
		}
		idx++;
	}
	game->map = m;
	return (SUCCESS);
}

static int	preprocessing(char **map, char *line, int *w)
{
	int	i;
	int	width;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ' && (line[i] < '0' || line[i] > '2') &&
			line[i] != 'E' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'W')
		{
			free(line);
			return (handle_error("map character is Invalid"));
		}
	}
	width = ft_strlen(line);
	if (*w < width)
		*w = width;
	*map = ft_strjoin(*map, line);
	if (*map == NULL)
		return (handle_error("failed to allocate memory"));
	return (SUCCESS);
}

static int	handle_gnl(char **map, int fd, int *h, int *w)
{
	char	*line;
	int		flag;
	int		is_start;

	is_start = FALSE;
	while ((flag = get_next_line(fd, &line)) == TRUE)
	{
		if (line[0] == 0)
		{
			free(line);
			if (is_start)
				return (handle_error("new line is not allowed between rows"));
		}
		else
		{
			is_start = TRUE;
			(*h)++;
			if (preprocessing(map, line, w) == ERROR)
				return (ERROR);
		}
	}
	if (flag == ERROR || (preprocessing(map, line, w)) == ERROR)
		return (ERROR);
	(*h)++;
	return (SUCCESS);
}

int			parse_map(t_game *game, int fd)
{
	char	*map;
	int		h;
	int		w;
	int		flag;

	map = NULL;
	h = 0;
	w = 0;
	if (handle_gnl(&map, fd, &h, &w) == ERROR)
		return (ERROR);
	if (h < 3 || w < 3)
	{
		free(map);
		return (handle_error("Map data is invalid"));
	}
	game->m_height = h;
	game->m_width = w;
	flag = get_map(game, map, -1, -1);
	free(map);
	if (flag == ERROR)
		return (ERROR);
	if (game->player.pos_x == -1.0 || game->player.pos_y == -1.0)
		return (handle_error("player position is undefined."));
	return (SUCCESS);
}
