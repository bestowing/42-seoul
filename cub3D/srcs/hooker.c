/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:50:34 by chelee            #+#    #+#             */
/*   Updated: 2021/02/19 16:19:42 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			move_mouse(int x, int y, t_game *game)
{
	if (game->player.life <= 0)
		return (0);
	if (x > game->s_width * 2 / 3)
	{
		game->player.move_dir = -1;
		game->player.turn_dir = -1;
	}
	else if (x < game->s_width / 3)
	{
		game->player.move_dir = +1;
		game->player.turn_dir = +1;
	}
	else
	{
		game->player.move_dir = 0;
		game->player.turn_dir = 0;
	}
	if (y > game->s_height * 2 / 3)
		game->player.ver_dir = -1;
	else if (y < game->s_height / 3)
		game->player.ver_dir = +1;
	else
		game->player.ver_dir = 0;
	return (0);
}

static int	press_key_cont(int keycode, t_game *game)
{
	if (keycode == KEY_2)
		game->player.curr_weapon = 1;
	else if (keycode == KEY_SPACE)
	{
		if (game->player.attack_time == 0)
			game->player.attack_time = 14;
	}
	else if (keycode == KEY_UP)
		game->player.ver_dir = +1;
	else if (keycode == KEY_DOWN)
		game->player.ver_dir = -1;
	else if (keycode == KEY_LEFT)
		game->player.turn_dir = +1;
	else if (keycode == KEY_RIGHT)
		game->player.turn_dir = -1;
	else if (keycode == KEY_M)
	{
		if (game->player.minimap == FALSE)
			game->player.minimap = TRUE;
		else
			game->player.minimap = FALSE;
	}
	else if (keycode == KEY_J && game->player.jump_time == 0)
		game->player.jump_time = JUMP_TIME;
	return (0);
}

int			press_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (game->player.life <= 0)
		return (0);
	else if (keycode >= KEY_2)
		return (press_key_cont(keycode, game));
	else if (keycode == KEY_W)
		game->player.walk_dir = +1;
	else if (keycode == KEY_S)
		game->player.walk_dir = -1;
	else if (keycode == KEY_A)
	{
		game->player.move_dir = +1;
		game->player.turn_dir = +1;
	}
	else if (keycode == KEY_D)
	{
		game->player.move_dir = -1;
		game->player.turn_dir = -1;
	}
	else if (keycode == KEY_1)
		game->player.curr_weapon = 0;
	else if (keycode == KEY_T)
		game->is_texture = TRUE;
	return (0);
}

int			release_key(int keycode, t_player *player)
{
	if (player->life <= 0)
		return (0);
	if (keycode == KEY_W || keycode == KEY_S)
		player->walk_dir = 0;
	else if (keycode == KEY_A || keycode == KEY_D)
	{
		player->move_dir = 0;
		player->turn_dir = 0;
	}
	else if (keycode == KEY_UP)
		player->ver_dir = 0;
	else if (keycode == KEY_DOWN)
		player->ver_dir = 0;
	else if (keycode == KEY_LEFT)
		player->turn_dir = 0;
	else if (keycode == KEY_RIGHT)
		player->turn_dir = 0;
	return (0);
}
