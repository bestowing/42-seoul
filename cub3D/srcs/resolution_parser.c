/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:44:41 by chelee            #+#    #+#             */
/*   Updated: 2021/02/19 10:44:42 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_nbr(char *line, int *w, int *h, int *idx)
{
	if (*w == -1)
		*w = ft_atoi(line, idx);
	else if (*h == -1)
		*h = ft_atoi(line, idx);
	else
		return (handle_error("resolution values are more than two."));
	return (SUCCESS);
}

static int	check_resolution(t_game *game, int w, int h)
{
	if (w == -1 || h == -1)
		return (handle_error("resolution value is less than two."));
	if (w < 0 || h < 0)
		return (handle_error("resolution value is invalid."));
	if (MAX_W < w)
		w = MAX_W;
	if (MAX_H < h)
		h = MAX_H;
	if (w < 480 || h < 380)
		return (handle_error("resolution value is too small."));
	game->s_width = w;
	game->s_height = h;
	return (SUCCESS);
}

static int	check_line(t_game *game, char *line)
{
	int	i;
	int	w;
	int	h;

	i = 1;
	w = -1;
	h = -1;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] >= '0' && line[i] <= '9')
		{
			if (handle_nbr(line, &w, &h, &i) == ERROR)
				return (ERROR);
		}
		else
			return (handle_error("resolution value is invalid."));
	}
	return (check_resolution(game, w, h));
}

int			handle_resolution(t_game *game, char *line)
{
	int	ret;

	ret = check_line(game, line);
	free(line);
	return (ret);
}
