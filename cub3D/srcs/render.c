/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 03:03:47 by chelee            #+#    #+#             */
/*   Updated: 2021/02/21 15:31:25 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cast_ray(t_render *rd, t_player p)
{
	if (rd->ray_dir_x < 0)
	{
		rd->step_x = -1;
		rd->side_dist_x = (p.pos_x - rd->map_x) * rd->delta_dist_x;
	}
	else
	{
		rd->step_x = 1;
		rd->side_dist_x = (rd->map_x + 1.0 - p.pos_x) * rd->delta_dist_x;
	}
	if (rd->ray_dir_y < 0)
	{
		rd->step_y = -1;
		rd->side_dist_y = (p.pos_y - rd->map_y) * rd->delta_dist_y;
	}
	else
	{
		rd->step_y = 1;
		rd->side_dist_y = (rd->map_y + 1.0 - p.pos_y) * rd->delta_dist_y;
	}
	return ;
}

static void	init_render(t_game *game, t_render *render, t_player player, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)game->s_width - 1;
	render->camera_x = camera_x;
	render->ray_dir_x = player.dir_x + player.plane_x * camera_x;
	render->ray_dir_y = player.dir_y + player.plane_y * camera_x;
	render->map_x = (int)(player.pos_x);
	render->map_y = (int)(player.pos_y);
	render->delta_dist_x = fabs(1 / render->ray_dir_x);
	render->delta_dist_y = fabs(1 / render->ray_dir_y);
	return ;
}

static int	get_tile_size(t_game *game)
{
	static int	size;

	if (size != 0)
		return (size);
	if (game->s_width >= game->s_height)
		size = game->s_height / 90;
	else
		size = game->s_width / 90;
	return (size);
}

void		render(t_game *game)
{
	t_render	render;
	t_player	player;
	int			x;

	render_floor_seiling(game, game->is_texture);
	player = game->player;
	x = -1;
	while (++x < game->s_width)
	{
		init_render(game, &render, player, x);
		cast_ray(&render, player);
		dda(&render, game, x);
		game->z_buffer[x] = render.perp_wall_dist;
	}
	render_sprite(game);
	render_hand(game);
	render_life(game);
	if (game->player.hit_time > 0 && game->enemy.life > 0)
		render_hit(game);
	render_map(game, player.pos_x, player.pos_y, get_tile_size(game));
	return ;
}
