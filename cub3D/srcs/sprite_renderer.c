/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_renderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:43:09 by chelee            #+#    #+#             */
/*   Updated: 2021/02/23 12:48:08 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_sprite_order(t_game *game)
{
	int	i;
	int	size;

	i = -1;
	size = game->item_size + 2;
	while (++i < size)
		game->sprite_order[i] = i;
	return ;
}

static int	get_distance(int px1, int py1, int px2, int py2)
{
	int	ret;

	ret = ((px1 - px2) * (px1 - px2) + (py1 - py2) * (py1 - py2));
	return (ret);
}

static void	set_sprite_distance(t_game *game)
{
	t_player	player;
	int			i;
	int			size;

	player = game->player;
	size = game->item_size;
	i = -1;
	while (++i < size)
		game->sprite_dis[i] =
			get_distance(player.pos_x, player.pos_y,
			game->items[i].pos_x, game->items[i].pos_y);
	game->sprite_dis[i] = get_distance(player.pos_x,
		player.pos_y, game->weapon.pos_x, game->weapon.pos_y);
	i++;
	game->sprite_dis[i] = get_distance(player.pos_x,
		player.pos_y, game->enemy.pos_x, game->enemy.pos_y);
	return ;
}

static int	chk_alive(t_game *game, int order)
{
	if (order == game->item_size)
	{
		if (game->weapon.life <= 0)
			return (FALSE);
		return (TRUE);
	}
	else if (order == game->item_size + 1)
	{
		if (game->enemy.life <= 0)
			return (FALSE);
		return (TRUE);
	}
	if (game->items[order].life <= 0)
		return (FALSE);
	return (TRUE);
}

void		render_sprite(t_game *game)
{
	int			weapon_n;
	int			enemy_n;
	int			i;

	weapon_n = game->item_size;
	enemy_n = weapon_n + 1;
	set_sprite_order(game);
	set_sprite_distance(game);
	sort_items(game->sprite_order, game->sprite_dis, 0, game->item_size + 1);
	i = game->item_size + 2;
	while (--i >= 0)
	{
		if (chk_alive(game, game->sprite_order[i]) == FALSE)
			continue ;
		if (game->sprite_order[i] == weapon_n)
			render_weapon(game);
		else if (game->sprite_order[i] == enemy_n)
			render_enemy(game);
		else
			render_item(game, game->sprite_order[i]);
	}
	return ;
}
