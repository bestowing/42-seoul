/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 09:06:53 by chelee            #+#    #+#             */
/*   Updated: 2021/02/19 12:22:09 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	act_enemy_cont(t_game *game, double dis_x, double dis_y)
{
	t_enemy	enemy;

	enemy = game->enemy;
	if (dis_x > 0.5 && dis_x > enemy.move_speed
		&& !game->map[(int)enemy.pos_y]
		[(int)(enemy.pos_x - enemy.move_speed - 0.5)])
		game->enemy.pos_x -= enemy.move_speed;
	else if (dis_x < -0.5 && dis_x < -enemy.move_speed &&
		!game->map[(int)enemy.pos_y]
		[(int)(enemy.pos_x + enemy.move_speed + 0.5)])
		game->enemy.pos_x += enemy.move_speed;
	if (dis_y > 0.5 && dis_y > enemy.move_speed &&
		!game->map[(int)(enemy.pos_y - enemy.move_speed - 0.5)]
		[(int)(enemy.pos_x)])
		game->enemy.pos_y -= enemy.move_speed;
	else if (dis_y < -0.5 && dis_y < -enemy.move_speed &&
		!game->map[(int)(enemy.pos_y + enemy.move_speed + 0.5)]
		[(int)(enemy.pos_x)])
		game->enemy.pos_y += enemy.move_speed;
	return ;
}

void		act_enemy(t_game *game)
{
	t_enemy		enemy;
	t_player	player;
	double		dis_x;
	double		dis_y;

	enemy = game->enemy;
	if (enemy.hit_time > 0)
		game->enemy.hit_time -= 1;
	player = game->player;
	dis_x = enemy.pos_x - player.pos_x;
	dis_y = enemy.pos_y - player.pos_y;
	act_enemy_cont(game, dis_x, dis_y);
	return ;
}
