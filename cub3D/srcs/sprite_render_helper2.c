/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_render_helper2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:38:12 by chelee            #+#    #+#             */
/*   Updated: 2021/02/23 19:42:38 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			*get_render_info(void)
{
	static int	render_info[8];

	return (render_info);
}

void		set_info_z(t_game *game, double tr_x, double tr_y, double pos_z)
{
	int			*render_info;

	render_info = get_render_info();
	render_info[SPRITE_SCR_X] = (int)((game->s_width / 2) * (1 + tr_x / tr_y));
	render_info[SPRITE_HEIGHT] = abs((int)(game->s_height / tr_y)) / VDIV;
	render_info[V_MOVE_SCREEN] = (int)((192 + pos_z) / tr_y)
		+ game->player.pitch + game->player.pos_z / tr_y;
	render_info[DRAW_START_Y] = (-render_info[SPRITE_HEIGHT]) / 2
		+ (game->s_height / 2) + render_info[V_MOVE_SCREEN];
	if (render_info[DRAW_START_Y] < 0)
		render_info[DRAW_START_Y] = 0;
	render_info[DRAW_END_Y] = render_info[SPRITE_HEIGHT] / 2
		+ game->s_height / 2 + render_info[V_MOVE_SCREEN];
	if (render_info[DRAW_END_Y] >= game->s_height)
		render_info[DRAW_END_Y] = game->s_height - 1;
	render_info[SPRITE_WIDTH] = abs((int)(game->s_height / tr_y)) / UDIV;
	render_info[DRAW_START_X] = (-render_info[SPRITE_WIDTH]) / 2
		+ render_info[SPRITE_SCR_X];
	if (render_info[DRAW_START_X] < 0)
		render_info[DRAW_START_X] = 0;
	render_info[DRAW_END_X] = render_info[SPRITE_WIDTH] / 2
		+ render_info[SPRITE_SCR_X];
	if (render_info[DRAW_END_X] >= game->s_width)
		render_info[DRAW_END_X] = game->s_width - 1;
	return ;
}

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void		set_render_info(t_game *game, double tr_x, double tr_y)
{
	int			*render_info;

	render_info = get_render_info();
	render_info[SPRITE_SCR_X] = (int)((game->s_width / 2) * (1 + tr_x / tr_y));
	render_info[SPRITE_HEIGHT] = ft_abs((int)(game->s_height / tr_y));
	render_info[V_MOVE_SCREEN] = game->player.pitch + game->player.pos_z / tr_y;
	render_info[DRAW_START_Y] = (-render_info[SPRITE_HEIGHT]) / 2
		+ (game->s_height / 2) + render_info[V_MOVE_SCREEN];
	if (render_info[DRAW_START_Y] < 0)
		render_info[DRAW_START_Y] = 0;
	render_info[DRAW_END_Y] = render_info[SPRITE_HEIGHT] / 2
		+ game->s_height / 2 + render_info[V_MOVE_SCREEN];
	if (render_info[DRAW_END_Y] >= game->s_height)
		render_info[DRAW_END_Y] = game->s_height - 1;
	render_info[SPRITE_WIDTH] = ft_abs((int)(game->s_height / tr_y));
	render_info[DRAW_START_X] = -(render_info[SPRITE_WIDTH]) / 2
		+ render_info[SPRITE_SCR_X];
	if (render_info[DRAW_START_X] < 0)
		render_info[DRAW_START_X] = 0;
	render_info[DRAW_END_X] = render_info[SPRITE_WIDTH] / 2
		+ render_info[SPRITE_SCR_X];
	if (render_info[DRAW_END_X] >= game->s_width)
		render_info[DRAW_END_X] = game->s_width - 1;
	return ;
}
