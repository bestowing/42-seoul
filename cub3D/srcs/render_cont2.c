/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cont2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 05:51:16 by chelee            #+#    #+#             */
/*   Updated: 2021/02/23 10:31:35 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_draw_start(t_render *rd, t_game *g, int lh)
{
	int	draw_start;

	draw_start = -lh / 2 + g->s_height / 2 + g->player.pitch
		+ (g->player.pos_z / rd->perp_wall_dist);
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

static int	get_draw_end(t_render *rd, t_game *g, int lh)
{
	int	draw_end;

	draw_end = lh / 2 + g->s_height / 2 + g->player.pitch
		+ (g->player.pos_z / rd->perp_wall_dist);
	if (draw_end >= g->s_height)
		draw_end = g->s_height - 1;
	return (draw_end);
}

static int	get_tex_x(t_render *rd, t_game *game, int side, int is_init)
{
	double		wall_x;
	static int	tex_x;
	int			tex_width;

	if (is_init == FALSE)
		return (tex_x);
	tex_width = game->tex_walls[0].width;
	if (side == 0)
		wall_x = game->player.pos_y + rd->perp_wall_dist * rd->ray_dir_y;
	else
		wall_x = game->player.pos_x + rd->perp_wall_dist * rd->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex_width);
	if (side == 0 && rd->ray_dir_x > 0)
		tex_x = tex_width - tex_x - 1;
	if (side == 1 && rd->ray_dir_y < 0)
		tex_x = tex_width - tex_x - 1;
	return (tex_x);
}

static int	get_color(t_render *rd, t_game *g, int side, double tp)
{
	int	tex_x;
	int	tex_y;
	int	color;
	int	tex_width;

	tex_width = g->tex_walls[0].width;
	tex_x = get_tex_x(rd, g, side, FALSE);
	tex_y = (int)tp & (g->tex_walls[0].height - 1);
	if (side == 0)
	{
		if (rd->ray_dir_x < 0.0)
			color = g->tex_walls[WEST].data[tex_width * tex_y + tex_x];
		else
			color = g->tex_walls[EAST].data[tex_width * tex_y + tex_x];
	}
	else
	{
		if (rd->ray_dir_y < 0.0)
			color = g->tex_walls[NORTH].data[tex_width * tex_y + tex_x];
		else
			color = g->tex_walls[SOUTH].data[tex_width * tex_y + tex_x];
	}
	if (side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}

void		dda_cont(t_render *render, t_game *game, int side, int x)
{
	int		line_height;
	int		draw_end;
	int		h;
	double	tex_pos;

	line_height = (int)(game->s_height / render->perp_wall_dist);
	draw_end = get_draw_end(render, game, line_height);
	get_tex_x(render, game, side, TRUE);
	h = get_draw_start(render, game, line_height) - 1;
	tex_pos = (h + 1 - game->player.pitch - (game->player.pos_z
		/ render->perp_wall_dist) - game->s_height / 2 + line_height / 2)
		* (1.0 * game->tex_walls[0].height / line_height);
	while (++h < draw_end)
	{
		(game->img.data)[h * game->s_width + x] =
			get_color(render, game, side, tex_pos);
		tex_pos += (1.0 * game->tex_walls[0].height / line_height);
	}
	return ;
}
