/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 02:50:45 by chelee            #+#    #+#             */
/*   Updated: 2021/02/23 13:25:48 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_item_data(t_game *game, int h, int w, int i)
{
	if (game->map[h][w] == 2)
	{
		game->items[i].move_dir = -1;
		game->items[i].hit_time = 0;
		game->items[i].life = 1;
		game->items[i].pos_x = w + 0.5;
		game->items[i].pos_y = h + 0.5;
		game->items[i].pos_z = 0.0;
		game->items[i].move_speed = I_M_SPEED;
	}
	else if (game->map[h][w] == 3)
	{
		game->weapon.move_dir = -1;
		game->weapon.hit_time = 0;
		game->weapon.life = 1;
		game->weapon.pos_x = w + 0.5;
		game->weapon.pos_y = h + 0.5;
		game->weapon.pos_z = 0.0;
		game->weapon.move_speed = I_M_SPEED;
	}
	game->map[h][w] = 0;
	return ;
}

static int	set_items(t_game *game)
{
	int		i;
	int		h;
	int		w;

	if (!(game->items = malloc(sizeof(t_item) * game->item_size)))
		return (ERROR);
	h = -1;
	i = -1;
	while (++h < game->m_height)
	{
		w = -1;
		while (++w < game->m_width)
		{
			if (game->map[h][w] == 2)
				i++;
			if (game->map[h][w] == 2 || game->map[h][w] == 3)
				set_item_data(game, h, w, i);
		}
	}
	return (SUCCESS);
}

static int	set_enemy(t_game *game)
{
	t_enemy	enemy;

	enemy.pos_x = game->weapon.pos_x;
	enemy.pos_y = game->weapon.pos_y;
	enemy.pos_z = 0.0;
	enemy.move_speed = E_M_SPEED;
	enemy.hit_time = 0;
	enemy.life = 10;
	enemy.img.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/enemy.xpm", &enemy.img.width, &enemy.img.height);
	enemy.img.data = (int *)mlx_get_data_addr(enemy.img.img_ptr,
		&(enemy.img.bpp), &(enemy.img.size_l), &(enemy.img.endian));
	game->enemy = enemy;
	return (SUCCESS);
}

int			set_game(t_game *game)
{
	set_player(game, game->player);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
		game->s_width, game->s_height, "cub3D");
	if (game->win_ptr == NULL)
		return (ERROR);
	game->img.img_ptr = mlx_new_image(game->mlx_ptr,
		game->s_width, game->s_height);
	if (game->img.img_ptr != NULL)
		game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr,
			&(game->img.bpp), &(game->img.size_l), &(game->img.endian));
	if (!(game->img.img_ptr) || !(game->img.data))
		return (ERROR);
	if (!(game->z_buffer = malloc(sizeof(double) * game->s_width)))
		return (ERROR);
	if (!(game->sprite_dis = malloc(sizeof(int) * (game->item_size + 2))))
		return (ERROR);
	if (!(game->sprite_order = malloc(sizeof(int) * (game->item_size + 2))))
		return (ERROR);
	if (set_textures(game) == ERROR)
		return (ERROR);
	if (set_items(game) == ERROR)
		return (ERROR);
	if (set_enemy(game) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
