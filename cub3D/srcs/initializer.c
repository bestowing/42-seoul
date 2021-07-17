/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:56:12 by chelee            #+#    #+#             */
/*   Updated: 2021/02/22 03:44:50 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_game *game)
{
	t_player	player;

	player.pos_x = -1.0;
	player.pos_y = -1.0;
	player.pos_z = 0.0;
	player.life = 3;
	player.plane_x = 0;
	player.plane_y = 0;
	player.pitch = 0;
	player.move_speed = 0.08;
	player.rot_speed = 0.03;
	player.turn_dir = 0;
	player.walk_dir = 0;
	player.move_dir = 0;
	player.ver_dir = 0;
	player.hit_time = 0;
	player.attack_time = 0;
	player.jump_time = 0;
	player.has_weapon = FALSE;
	player.curr_weapon = 0;
	player.minimap = FALSE;
	game->player = player;
	return ;
}

int			init_game(t_game *game)
{
	if (!(game->mlx_ptr = mlx_init()))
		return (handle_error("failed to init mlx"));
	game->win_ptr = NULL;
	game->map = NULL;
	game->sprite_order = NULL;
	game->sprite_dis = NULL;
	game->item_size = 0;
	game->is_texture = FALSE;
	init_textures(game);
	game->img.img_ptr = NULL;
	game->img.data = NULL;
	init_player(game);
	game->z_buffer = NULL;
	game->enemy.img.img_ptr = NULL;
	game->enemy.img.data = NULL;
	game->items = NULL;
	return (SUCCESS);
}
