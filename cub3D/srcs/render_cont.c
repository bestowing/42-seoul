/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:30:09 by chelee            #+#    #+#             */
/*   Updated: 2021/02/20 05:51:29 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_side_dist(t_render *render)
{
	if (render->side_dist_x < render->side_dist_y)
	{
		render->side_dist_x += render->delta_dist_x;
		render->map_x += render->step_x;
		return (FALSE);
	}
	render->side_dist_y += render->delta_dist_y;
	render->map_y += render->step_y;
	return (TRUE);
}

void		dda(t_render *render, t_game *game, int x)
{
	int hit;
	int	side;

	hit = FALSE;
	while (hit == FALSE)
	{
		side = handle_side_dist(render);
		if (game->map[render->map_y][render->map_x] > 0)
			hit = TRUE;
	}
	if (!side)
	{
		render->perp_wall_dist = (render->map_x - game->player.pos_x
			+ (1 - render->step_x) / 2) / render->ray_dir_x;
	}
	else
	{
		render->perp_wall_dist = (render->map_y - game->player.pos_y
			+ (1 - render->step_y) / 2) / render->ray_dir_y;
	}
	dda_cont(render, game, side, x);
	return ;
}
