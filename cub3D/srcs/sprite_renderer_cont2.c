/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_renderer_cont2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 04:02:57 by chelee            #+#    #+#             */
/*   Updated: 2021/02/22 04:03:44 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		render_enemy_cont(t_game *game, int tex_x, int *info, int x)
{
	int	y;
	int	d;
	int	tex_y;
	int	color;

	y = info[DRAW_START_Y] - 1;
	while (++y < info[DRAW_END_Y])
	{
		d = (y - info[V_MOVE_SCREEN]) * 256
			- game->s_height * 128 + info[SPRITE_HEIGHT] * 128;
		tex_y = ((d * game->enemy.img.height) / info[SPRITE_HEIGHT]) / 256;
		color = (game->enemy.img.data)[game->enemy.img.width * tex_y + tex_x];
		if ((color & 0x00FFFFFF) == 0)
			continue ;
		(game->img.data)[y * game->s_width + x] =
			game->enemy.hit_time == 0 ? color : effect_hit_color(color);
	}
	return ;
}

void			render_enemy(t_game *game)
{
	double		transform_x;
	double		transform_y;
	int			*info;
	int			tex_x;
	int			x;

	transform_x = get_transforms(game->player,
		game->enemy.pos_x, game->enemy.pos_y, &transform_y);
	set_render_info(game, transform_x, transform_y);
	info = get_render_info();
	x = info[DRAW_START_X] - 1;
	while (++x < info[DRAW_END_X])
	{
		tex_x = (int)(256 * (x - (-info[SPRITE_WIDTH] / 2
			+ info[SPRITE_SCR_X])) * game->enemy.img.width
			/ info[SPRITE_WIDTH]) / 256;
		if (transform_y > 0 && x > 0 && x < game->s_width &&
			transform_y < game->z_buffer[x])
			render_enemy_cont(game, tex_x, info, x);
	}
	return ;
}
