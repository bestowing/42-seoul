/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 00:20:29 by chelee            #+#    #+#             */
/*   Updated: 2021/02/23 18:47:28 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_player(t_game *game, t_player player)
{
	game->player.move_x = player.dir_x;
	game->player.move_y = player.dir_y;
	if (player.dir_x == 1 && player.dir_y == 0)
		game->player.plane_y = -0.66;
	else if (player.dir_x == -1 && player.dir_y == 0)
		game->player.plane_y = +0.66;
	else if (player.dir_x == 0 && player.dir_y == 1)
		game->player.plane_x = +0.66;
	else
		game->player.plane_x = -0.66;
	return ;
}

static void	player_hit(t_game *game, double pos_x, double pos_y)
{
	t_player	p;
	int			n_pos_y;
	int			n_pos_x;

	p = game->player;
	if (fabs(pos_x - game->enemy.pos_x) >= 0.6 ||
		fabs(pos_y - game->enemy.pos_y) >= 0.6)
		return ;
	game->player.life -= 1;
	game->player.hit_time = 100;
	n_pos_y = pos_y + p.move_y * -1.5;
	n_pos_x = pos_x + p.move_x * -1.5;
	if (n_pos_y < 0 || n_pos_y >= game->m_height ||
		n_pos_x < 0 || n_pos_x >= game->m_width)
		return ;
	if (game->map[n_pos_y][n_pos_x] == 0)
	{
		game->player.pos_x += p.move_x * -1.5;
		game->player.pos_y += p.move_y * -1.5;
	}
	return ;
}

static void	player_get_weapon(t_game *game)
{
	double	pos_x;
	double	pos_y;

	if (game->weapon.life == 0)
		return ;
	pos_x = game->player.pos_x;
	pos_y = game->player.pos_y;
	if (fabs(pos_x - game->weapon.pos_x) < 0.6 &&
		fabs(pos_y - game->weapon.pos_y) < 0.6)
	{
		game->player.has_weapon = TRUE;
		game->player.curr_weapon = 1;
		game->weapon.life = 0;
	}
	return ;
}

static void	player_get_item(t_game *game)
{
	double	pos_x;
	double	pos_y;
	int		i;

	if (game->player.life >= 5)
		return ;
	i = -1;
	while (++i < game->item_size)
	{
		if (game->items[i].life <= 0)
			continue ;
		pos_x = game->player.pos_x;
		pos_y = game->player.pos_y;
		if (fabs(pos_x - game->items[i].pos_x) < 0.6 &&
			fabs(pos_y - game->items[i].pos_y) < 0.6)
		{
			game->player.life += 1;
			game->items[i].life = 0;
		}
	}
	return ;
}

void		act_player(t_game *game)
{
	player_move(game);
	if (game->player.jump_time > 0)
	{
		if (game->player.jump_time > JUMP_TIME / 2)
			game->player.pos_z += 20;
		else
			game->player.pos_z -= 20;
		game->player.jump_time -= 1;
	}
	player_get_weapon(game);
	player_get_item(game);
	if (game->player.attack_time > 0)
		player_attack(game);
	if (game->player.hit_time)
		game->player.hit_time--;
	else if (game->enemy.life > 0)
		player_hit(game, game->player.pos_x, game->player.pos_y);
	return ;
}
