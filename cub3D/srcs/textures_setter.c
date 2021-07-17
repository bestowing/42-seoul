/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_setter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 01:47:10 by chelee            #+#    #+#             */
/*   Updated: 2021/02/26 16:14:29 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_textures_floor_and_ceiling(t_game *game)
{
	game->floor.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/wood.xpm", &game->floor.width, &game->floor.height);
	if (game->floor.img_ptr != NULL)
		game->floor.data = (int *)mlx_get_data_addr(game->floor.img_ptr,
			&(game->floor.bpp), &(game->floor.size_l), &(game->floor.endian));
	game->ceiling.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/sand.xpm", &game->ceiling.width, &game->ceiling.height);
	if (game->floor.img_ptr != NULL)
		game->ceiling.data = (int *)mlx_get_data_addr(game->ceiling.img_ptr,
			&(game->ceiling.bpp), &(game->ceiling.size_l),
			&(game->ceiling.endian));
	return ;
}

static void	set_textures_hand(t_game *g)
{
	g->tex_hand[0].img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
		"./textures/hand.xpm", &(g->tex_hand[0].width),
		&(g->tex_hand[0].height));
	if (g->tex_hand[0].img_ptr != NULL)
		g->tex_hand[0].data =
			(int *)mlx_get_data_addr(g->tex_hand[0].img_ptr,
			&(g->tex_hand[0].bpp), &(g->tex_hand[0].size_l),
			&(g->tex_hand[0].endian));
	g->tex_hand[1].img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
		"./textures/attack_hand.xpm", &g->tex_hand[1].width,
		&g->tex_hand[1].height);
	if (g->tex_hand[1].img_ptr != NULL)
		g->tex_hand[1].data =
			(int *)mlx_get_data_addr(g->tex_hand[1].img_ptr,
			&(g->tex_hand[1].bpp), &(g->tex_hand[1].size_l),
			&(g->tex_hand[1].endian));
	return ;
}

static void	set_textures_weapon(t_game *g)
{
	g->tex_weapon[0].img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
		"./textures/sword_walk.xpm", &g->tex_weapon[0].width,
		&g->tex_weapon[0].height);
	if (g->tex_weapon[0].img_ptr != NULL)
		g->tex_weapon[0].data =
			(int *)mlx_get_data_addr(g->tex_weapon[0].img_ptr,
			&(g->tex_weapon[0].bpp), &(g->tex_weapon[0].size_l),
			&(g->tex_weapon[0].endian));
	g->tex_weapon[1].img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
		"./textures/sword_attack1.xpm", &g->tex_weapon[1].width,
		&g->tex_weapon[1].height);
	if (g->tex_weapon[1].img_ptr != NULL)
		g->tex_weapon[1].data =
			(int *)mlx_get_data_addr(g->tex_weapon[1].img_ptr,
			&(g->tex_weapon[1].bpp), &(g->tex_weapon[1].size_l),
			&(g->tex_weapon[1].endian));
	g->tex_weapon[2].img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
		"./textures/sword_attack2.xpm", &g->tex_weapon[2].width,
		&g->tex_weapon[2].height);
	if (g->tex_weapon[2].img_ptr != NULL)
		g->tex_weapon[2].data =
			(int *)mlx_get_data_addr(g->tex_weapon[2].img_ptr,
			&(g->tex_weapon[2].bpp), &(g->tex_weapon[2].size_l),
			&(g->tex_weapon[2].endian));
	return ;
}

static void	set_textures_etc(t_game *g)
{
	g->sword.img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
		"./textures/sword.xpm", &g->sword.width, &g->sword.height);
	if (g->sword.img_ptr != NULL)
		g->sword.data = (int *)mlx_get_data_addr(g->sword.img_ptr,
			&(g->sword.bpp), &(g->sword.size_l), &(g->sword.endian));
	g->life[0].img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
		"./textures/life.xpm", &g->life[0].width, &g->life[0].height);
	if (g->life[0].img_ptr != NULL)
		g->life[0].data = (int *)mlx_get_data_addr(g->life[0].img_ptr,
			&(g->life[0].bpp), &(g->life[0].size_l), &(g->life[0].endian));
	g->life[1].img_ptr = mlx_xpm_file_to_image(g->mlx_ptr,
		"./textures/empty_life.xpm",
		&g->life[1].width, &g->life[1].height);
	if (g->life[1].img_ptr != NULL)
		g->life[1].data = (int *)mlx_get_data_addr(g->life[1].img_ptr,
			&(g->life[1].bpp), &(g->life[1].size_l), &(g->life[1].endian));
	return ;
}

int			set_textures(t_game *game)
{
	set_textures_floor_and_ceiling(game);
	set_textures_hand(game);
	set_textures_weapon(game);
	set_textures_etc(game);
	if (!(game->floor.data) || !(game->ceiling.data) ||
		!(game->tex_hand[0].data) || !(game->tex_hand[1].data) ||
		!(game->tex_weapon[0].data) || !(game->tex_weapon[1].data) ||
		!(game->tex_weapon[2].data) || !(game->sword.data) ||
		!(game->life[0].data) || !(game->life[1].data))
	{
		handle_error("failed to read xpm files.\n");
		exit_game(game);
	}
	return (SUCCESS);
}
