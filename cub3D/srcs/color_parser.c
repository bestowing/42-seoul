/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:45:49 by chelee            #+#    #+#             */
/*   Updated: 2021/02/19 10:45:51 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_nbr(char *str, int *idx, int *target)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = *idx;
	while (ft_isnbr(str[i]))
	{
		tmp *= 10;
		tmp += str[i++] - '0';
		if (tmp > 255)
			return (ERROR);
	}
	*idx = i;
	*target = tmp;
	return (SUCCESS);
}

static int	parse_nbr_cont(t_game *game, int rgb[3], char *str, int is_floor)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i++] != ',')
		return (ERROR);
	while (str[i] == ' ')
		i++;
	if (check_nbr(str, &i, rgb + 2) == ERROR)
		return (ERROR);
	if (rgb[0] == -1 || rgb[1] == -1 || rgb[2] == -1)
		return (ERROR);
	if (str[i] != 0)
		return (ERROR);
	if (is_floor)
		game->floor_color = ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
	else
		game->ceiling_color = ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
	return (SUCCESS);
}

static int	parse_nbr(t_game *game, char *str, int is_floor)
{
	int	rgb[3];
	int	i;

	rgb[0] = -1;
	rgb[1] = -1;
	rgb[2] = -1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (check_nbr(str, &i, rgb) == ERROR)
		return (ERROR);
	while (str[i] == ' ')
		i++;
	if (str[i++] != ',')
		return (ERROR);
	while (str[i] == ' ')
		i++;
	if (check_nbr(str, &i, rgb + 1) == ERROR)
		return (ERROR);
	return (parse_nbr_cont(game, rgb, str + i, is_floor));
}

int			handle_color(t_game *game, char *line, int is_floor)
{
	char	*str;
	int		i;
	int		start;
	int		size;
	int		flag;

	i = 1;
	while (line[i] && line[i] == ' ')
		i++;
	start = i;
	while (line[i])
		i++;
	size = i - start;
	str = ft_substr(line, start, size);
	if (str == NULL)
		return (handle_error("failed to allocate memory"));
	flag = parse_nbr(game, str, is_floor);
	free(str);
	if (flag == ERROR)
		return (handle_error("RGB values are invalid"));
	return (SUCCESS);
}
