/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handler_cont.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 09:20:21 by chelee            #+#    #+#             */
/*   Updated: 2021/02/23 19:37:32 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_move_cont(t_game *g, t_player p)
{
	if (!g->map[(int)(p.pos_y + p.move_y * p.move_speed * p.walk_dir)]
		[(int)(p.pos_x + p.move_x * p.move_speed * p.walk_dir)])
	{
		g->player.pos_x += p.move_x * p.move_speed * p.walk_dir;
		g->player.pos_y += p.move_y * p.move_speed * p.walk_dir;
	}
	if (p.ver_dir == 1)
	{
		if (p.pitch + 400 * p.move_speed <= 200)
			g->player.pitch = p.pitch + 400 * p.move_speed;
	}
	else if (p.ver_dir == -1)
	{
		if (p.pitch + 400 * -p.move_speed >= -200)
			g->player.pitch = p.pitch + 400 * -p.move_speed;
	}
	return ;
}

void		player_move(t_game *g)
{
	t_player	p;

	p = g->player;
	g->player.move_x = p.move_x * cos(p.rot_speed * p.move_dir) - p.move_y *
		sin(p.rot_speed * p.move_dir);
	g->player.move_y = p.move_x * sin(p.rot_speed * p.move_dir) + p.move_y *
		cos(p.rot_speed * p.move_dir);
	g->player.dir_x = p.dir_x * cos(p.rot_speed * p.turn_dir) - p.dir_y *
		sin(p.rot_speed * p.turn_dir);
	g->player.dir_y = p.dir_x * sin(p.rot_speed * p.turn_dir) + p.dir_y *
		cos(p.rot_speed * p.turn_dir);
	g->player.plane_x = p.plane_x * cos(p.rot_speed * p.turn_dir) -
		p.plane_y * sin(p.rot_speed * p.turn_dir);
	g->player.plane_y = p.plane_x * sin(p.rot_speed *
		p.turn_dir) + p.plane_y * cos(p.rot_speed * p.turn_dir);
	player_move_cont(g, p);
	return ;
}

static int	is_hit_cont(double transform_y, int start_x, int end_x, int w)
{
	int	left_range;
	int	right_range;

	left_range = w / 3;
	right_range = left_range * 2;
	if (transform_y > 0 && start_x < left_range && end_x > right_range)
		return (TRUE);
	return (FALSE);
}

static int	is_hit(t_enemy enemy, t_player player, int w, int h)
{
	double	inv_det;
	double	transform_y;
	double	transform_x;
	int		sprite_screen_x;
	int		sprite_width;

	if (enemy.hit_time > 0)
		return (FALSE);
	if (fabs(enemy.pos_x - player.pos_x) >= 1.3)
		return (FALSE);
	if (fabs(enemy.pos_y - player.pos_y) >= 1.3)
		return (FALSE);
	inv_det = 1.0 /
		(player.plane_x * player.dir_y - player.dir_x * player.plane_y);
	transform_y = inv_det * (-player.plane_y * (enemy.pos_x - player.pos_x)
		+ player.plane_x * (enemy.pos_y - player.pos_y));
	transform_x = inv_det * (player.dir_y * (enemy.pos_x - player.pos_x)
		- player.dir_x * (enemy.pos_y - player.pos_y));
	sprite_screen_x = (int)((w / 2) * (1 + transform_x / transform_y));
	sprite_width = (int)(h / transform_y);
	sprite_width = sprite_width < 0 ? -sprite_width : sprite_width;
	return (is_hit_cont(transform_y, (-sprite_width / 2 + sprite_screen_x),
		(sprite_width / 2 + sprite_screen_x), w));
}

void		player_attack(t_game *game)
{
	t_enemy		enemy;
	t_player	player;
	int			n_pos_x;
	int			n_pos_y;

	game->player.attack_time -= 1;
	enemy = game->enemy;
	player = game->player;
	if (!(is_hit(enemy, player, game->s_width, game->s_height)))
		return ;
	if (player.curr_weapon && player.has_weapon)
		game->enemy.life -= 4;
	else
		game->enemy.life -= 1;
	game->enemy.hit_time = 50;
	n_pos_x = enemy.pos_x + player.move_x * 0.9;
	n_pos_y = enemy.pos_y + player.move_y * 0.9;
	if (n_pos_y < 0 || n_pos_y >= game->m_height ||
		n_pos_x < 0 || n_pos_x >= game->m_width)
		return ;
	if (game->map[n_pos_y][n_pos_x])
		return ;
	game->enemy.pos_x += player.move_x * 0.9;
	game->enemy.pos_y += player.move_y * 0.9;
	return ;
}
