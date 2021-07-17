/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect_renderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 04:26:15 by chelee            #+#    #+#             */
/*   Updated: 2021/02/20 04:47:24 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			effect_hit_color(int old)
{
	double	weight;
	int		red;
	int		green;
	int		blue;

	weight = (double)51 / 255;
	red = (weight * 0xac) + (1 - weight) * ((old >> 16) & 0xFF);
	green = (1 - weight) * ((old >> 8) & 0xFF);
	blue = (1 - weight) * (old & 0xFF);
	return ((red << 16) | (green << 8) | blue);
}

void		render_hit(t_game *game)
{
	int		old;
	int		h;
	int		w;

	h = -1;
	while (++h < game->s_height)
	{
		w = -1;
		while (++w < game->s_width)
		{
			old = (game->img.data)[h * game->s_width + w];
			(game->img.data)[h * game->s_width + w] = effect_hit_color(old);
		}
	}
	return ;
}
