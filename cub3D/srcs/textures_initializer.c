/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_initializer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:50:37 by chelee            #+#    #+#             */
/*   Updated: 2021/02/26 16:12:53 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_textures_floor_and_ceiling(t_game *game)
{
	game->floor.img_ptr = NULL;
	game->ceiling.img_ptr = NULL;
	game->floor.data = NULL;
	game->ceiling.data = NULL;
	return ;
}

static void	init_textures_hand(t_game *game)
{
	game->tex_hand[0].img_ptr = NULL;
	game->tex_hand[0].data = NULL;
	game->tex_hand[1].img_ptr = NULL;
	game->tex_hand[1].data = NULL;
	return ;
}

static void	init_textures_weapon(t_game *game)
{
	game->tex_weapon[0].img_ptr = NULL;
	game->tex_weapon[1].img_ptr = NULL;
	game->tex_weapon[2].img_ptr = NULL;
	game->tex_weapon[0].data = NULL;
	game->tex_weapon[1].data = NULL;
	game->tex_weapon[2].data = NULL;
	return ;
}

static void	init_textures_etc(t_game *game)
{
	game->sword.img_ptr = NULL;
	game->sword.data = NULL;
	game->life[0].img_ptr = NULL;
	game->life[1].img_ptr = NULL;
	game->life[0].data = NULL;
	game->life[1].data = NULL;
	return ;
}

void		init_textures(t_game *game)
{
	init_textures_floor_and_ceiling(game);
	init_textures_hand(game);
	init_textures_weapon(game);
	init_textures_etc(game);
	return ;
}
