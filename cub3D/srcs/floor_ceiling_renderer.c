/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_renderer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:34:48 by chelee            #+#    #+#             */
/*   Updated: 2021/02/19 17:01:04 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		render_color(t_game *game, int y, int is_floor, float rd)
{
	float	floor_step_x;
	float	floor_step_y;
	float	floor_x;
	float	floor_y;
	int		x;

	floor_step_x = rd * (game->player.plane_x * 2) / game->s_width;
	floor_step_y = rd * (game->player.plane_y * 2) / game->s_width;
	floor_x = game->player.pos_x + rd
		* (game->player.dir_x - game->player.plane_x);
	floor_y = game->player.pos_y + rd
		* (game->player.dir_y - game->player.plane_y);
	x = -1;
	while (++x < game->s_width)
	{
		floor_x += floor_step_x;
		floor_y += floor_step_y;
		if (is_floor)
			(game->img.data)[y * game->s_width + x] =
			((game->floor_color) >> 1) & 8355711;
		else
			(game->img.data)[y * game->s_width + x] =
			((game->ceiling_color) >> 1) & 8355711;
	}
	return ;
}

static int		get_color(t_game *g, float f_x, float f_y, int is_f)
{
	int	c_x;
	int	c_y;
	int	tx;
	int	ty;

	c_x = (int)f_x;
	c_y = (int)f_y;
	if (is_f)
	{
		tx = (int)(g->floor.width * (f_x - c_x)) & (g->floor.width - 1);
		ty = (int)(g->floor.height * (f_y - c_y)) & (g->floor.height - 1);
	}
	else
	{
		tx = (int)(g->ceiling.width * (f_x - c_x)) & (g->ceiling.width - 1);
		ty = (int)(g->ceiling.height * (f_y - c_y)) & (g->ceiling.height - 1);
	}
	if (is_f)
		return (g->floor.width * ty + tx);
	return (g->ceiling.width * ty + tx);
}

static void		render_texture(t_game *g, int y, int is_floor, float rd)
{
	float	floor_step_x;
	float	floor_step_y;
	float	floor_x;
	float	floor_y;
	int		x;

	floor_step_x = rd * (g->player.plane_x * 2) / g->s_width;
	floor_step_y = rd * (g->player.plane_y * 2) / g->s_width;
	floor_x = g->player.pos_x + rd * (g->player.dir_x - g->player.plane_x);
	floor_y = g->player.pos_y + rd * (g->player.dir_y - g->player.plane_y);
	x = -1;
	while (++x < g->s_width)
	{
		if (is_floor)
			(g->img.data)[y * g->s_width + x] =
			((g->floor.data[get_color(g, floor_x,
			floor_y, is_floor)]) >> 1) & 8355711;
		else
			(g->img.data)[y * g->s_width + x] =
			((g->ceiling.data[get_color(g, floor_x,
			floor_y, is_floor)]) >> 1) & 8355711;
		floor_x += floor_step_x;
		floor_y += floor_step_y;
	}
	return ;
}

static float	get_row_distance(t_player player, int y, int h, int is_floor)
{
	float	row_distance;
	float	cam_z;
	int		p;

	if (is_floor)
		p = y - h / 2 - player.pitch;
	else
		p = h / 2 - y + player.pitch;
	cam_z = 0.5 * h;
	if (is_floor)
		cam_z += player.pos_z;
	else
		cam_z -= player.pos_z;
	row_distance = cam_z / p;
	return (row_distance);
}

void			render_floor_seiling(t_game *game, int is_texture)
{
	t_player	player;
	int			y;
	int			is_floor;
	float		row_distance;

	player = game->player;
	y = -1;
	while (++y < game->s_height)
	{
		is_floor = FALSE;
		if (y > game->s_height / 2 + player.pitch)
			is_floor = TRUE;
		row_distance = get_row_distance(player, y, game->s_height, is_floor);
		if (is_texture)
			render_texture(game, y, is_floor, row_distance);
		else
			render_color(game, y, is_floor, row_distance);
	}
	return ;
}
