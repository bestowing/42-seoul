/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_renderer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:51:46 by chelee            #+#    #+#             */
/*   Updated: 2021/02/20 04:44:57 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_life_cont(t_game *game, t_img texture, int h, int i)
{
	int		offset;
	int		color;
	int		w;

	offset = 20;
	w = -1;
	while (++w < texture.width)
	{
		color = texture.data[h * texture.width + w];
		if ((color & 0x00FFFFFF) != 0)
			(game->img.data)[((h + game->s_height - texture.width - offset)
				* game->s_width + (i * offset)) + offset + w] = color;
	}
}

void		render_life(t_game *game)
{
	t_img	texture;
	int		h;
	int		i;
	int		life_num;

	life_num = game->player.life;
	i = -1;
	while (++i < MAX_LIFE)
	{
		if (i < game->player.life)
			texture = game->life[0];
		else
			texture = game->life[1];
		h = -1;
		while (++h < texture.height)
			render_life_cont(game, texture, h, i);
	}
	return ;
}

static void	render_map_cont(t_game *game, int color, int sp, int tile)
{
	int	x;
	int	y;

	x = -1;
	while (++x < tile)
	{
		y = -1;
		while (++y < tile)
			(game->img.data)[sp + (x * game->s_width) + y] = color;
	}
	return ;
}

void		render_map(t_game *game, int px, int py, int tile)
{
	int	h;
	int	w;
	int	start_point;
	int	color;

	if (!(game->player.minimap))
		return ;
	h = -1;
	while (++h < game->m_height)
	{
		w = -1;
		while (++w < game->m_width)
		{
			start_point = (h * game->s_width * tile) + (w * tile);
			color = -1;
			if (game->map[h][w] == 1)
				color = 0;
			else if (px == w && py == h)
				color = 0xAC0000;
			if (color != -1)
				render_map_cont(game, color, start_point, tile);
		}
	}
	return ;
}
