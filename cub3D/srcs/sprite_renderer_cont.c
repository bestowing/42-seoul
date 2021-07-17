/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_renderer_cont.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:53:29 by chelee            #+#    #+#             */
/*   Updated: 2021/02/22 04:03:42 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double			get_transforms(t_player p, double px, double py, double *t_y)
{
	double	transform_x;
	double	sprite_x;
	double	sprite_y;
	double	inv_det;

	sprite_x = px - p.pos_x;
	sprite_y = py - p.pos_y;
	inv_det = 1.0 / (p.plane_x * p.dir_y - p.dir_x * p.plane_y);
	transform_x = inv_det * (p.dir_y * sprite_x - p.dir_x * sprite_y);
	*t_y = inv_det * (-p.plane_y * sprite_x + p.plane_x * sprite_y);
	return (transform_x);
}

static void		render_weapon_cont(t_game *game, int tex_x, int *info, int x)
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
		tex_y = ((d * game->sword.height) / info[SPRITE_HEIGHT]) / 256;
		color = (game->sword.data)[game->sword.width * tex_y + tex_x];
		if ((color & 0x00FFFFFF) == 0)
			continue ;
		(game->img.data)[y * game->s_width + x] = color;
	}
	return ;
}

void			render_weapon(t_game *game)
{
	double		transform_x;
	double		transform_y;
	int			*info;
	int			tex_x;
	int			x;

	transform_x = get_transforms(game->player,
		game->weapon.pos_x, game->weapon.pos_y, &transform_y);
	set_info_z(game, transform_x, transform_y, game->weapon.pos_z);
	info = get_render_info();
	x = info[DRAW_START_X] - 1;
	while (++x < info[DRAW_END_X])
	{
		tex_x = (int)(256 * (x - (-info[SPRITE_WIDTH] / 2
			+ info[SPRITE_SCR_X])) * game->sword.width
			/ info[SPRITE_WIDTH]) / 256;
		if (transform_y > 0 && x > 0 && x < game->s_width &&
			transform_y < game->z_buffer[x])
			render_weapon_cont(game, tex_x, info, x);
	}
	return ;
}

static void		render_item_cont(t_game *game, int tex_x, int *info, int x)
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
		tex_y = ((d * game->item.height) / info[SPRITE_HEIGHT]) / 256;
		color = (game->item.data)[game->item.width * tex_y + tex_x];
		if ((color & 0x00FFFFFF) == 0)
			continue ;
		(game->img.data)[y * game->s_width + x] = color;
	}
	return ;
}

void			render_item(t_game *game, int i)
{
	double		transform_x;
	double		transform_y;
	int			*info;
	int			tex_x;
	int			x;

	transform_x = get_transforms(game->player,
		game->items[i].pos_x, game->items[i].pos_y, &transform_y);
	set_info_z(game, transform_x, transform_y, game->items[i].pos_z);
	info = get_render_info();
	x = info[DRAW_START_X] - 1;
	while (++x < info[DRAW_END_X])
	{
		tex_x = (int)(256 * (x - (-info[SPRITE_WIDTH] / 2
			+ info[SPRITE_SCR_X])) * game->item.width
			/ info[SPRITE_WIDTH]) / 256;
		if (transform_y > 0 && x > 0 && x < game->s_width &&
			transform_y < game->z_buffer[x])
			render_item_cont(game, tex_x, info, x);
	}
	return ;
}
