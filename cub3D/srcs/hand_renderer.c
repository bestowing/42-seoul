/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:23:15 by chelee            #+#    #+#             */
/*   Updated: 2021/02/20 03:41:55 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_armed_attack(t_game *g, int w)
{
	t_img	texture;
	int		i;
	int		j;
	int		color;

	if (g->player.attack_time < 7)
		texture = g->tex_weapon[2];
	else
		texture = g->tex_weapon[1];
	i = -1;
	while (++i < texture.height)
	{
		j = -1;
		while (++j < texture.width)
		{
			color = texture.data[i * texture.width + j];
			if ((color & 0x00FFFFFF) != 0)
				(g->img.data)[(g->s_height - texture.width + i)
				* w + (w * 2 / 3 - texture.width + j)] = color;
		}
	}
	return ;
}

static void	render_empty_attack(t_game *g, t_img t, int h, int offset)
{
	int		w;
	int		i;
	int		j;
	int		color;
	int		idx;

	w = g->s_width;
	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < t.width)
		{
			color = t.data[i * t.width + j];
			if ((idx = (g->s_height - offset + i) * w
				+ (w * 2 / 3 - t.width + j)) > (w * g->s_height))
				continue ;
			if ((color & 0x00FFFFFF) != 0)
				(g->img.data)[idx] = color;
		}
	}
	return ;
}

static void	render_armed_hand(t_game *game, int w)
{
	int	i;
	int	j;
	int	hand_h;
	int	hand_w;
	int	color;

	hand_h = game->tex_weapon[0].height;
	hand_w = game->tex_weapon[0].width;
	i = -1;
	while (++i < hand_h)
	{
		j = -1;
		while (++j < hand_w)
		{
			color = game->tex_weapon[0].data[i * hand_w + j];
			if ((color & 0x00FFFFFF) != 0)
				(game->img.data)[(game->s_height - hand_h + i)
				* w + (w * 2 / 3 - hand_w + j)] = color;
		}
	}
	return ;
}

static void	render_empty_hand(t_game *game, int w)
{
	int	i;
	int	j;
	int	hand_h;
	int	hand_w;
	int	color;

	hand_h = game->tex_hand[0].height;
	hand_w = game->tex_hand[0].width;
	i = -1;
	while (++i < hand_h)
	{
		j = -1;
		while (++j < hand_w)
		{
			color = game->tex_hand[0].data[i * hand_w + j];
			if ((color & 0x00FFFFFF) != 0)
				(game->img.data)[(game->s_height - hand_w + i) *
				w + (w * 2 / 3 - hand_w + j)] = color;
		}
	}
	return ;
}

void		render_hand(t_game *g)
{
	t_player	p;

	p = g->player;
	if (p.attack_time > 0)
	{
		if (p.has_weapon && p.curr_weapon)
			render_armed_attack(g, g->s_width);
		else
		{
			if (p.attack_time < 7)
				render_empty_attack(g, g->tex_hand[1],
					g->tex_hand[1].height / 2, 100);
			else
				render_empty_attack(g, g->tex_hand[1],
					g->tex_hand[1].height, 196);
		}
	}
	else
	{
		if (p.has_weapon && p.curr_weapon)
			render_armed_hand(g, g->s_width);
		else
			render_empty_hand(g, g->s_width);
	}
	return ;
}
