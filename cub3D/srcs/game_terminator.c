/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_terminator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:11:36 by chelee            #+#    #+#             */
/*   Updated: 2021/02/26 16:16:21 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_textures_walls(t_game *game, void *mlx)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (game->tex_walls[i].img_ptr && game->tex_walls[i].data)
			mlx_destroy_image(mlx, game->tex_walls[i].img_ptr);
	return ;
}

static void	free_textures_floor_ceiling(t_game *game, void *mlx)
{
	if (game->ceiling.img_ptr && game->ceiling.data)
		mlx_destroy_image(mlx, game->ceiling.img_ptr);
	if (game->floor.img_ptr && game->floor.data)
		mlx_destroy_image(mlx, game->floor.img_ptr);
	return ;
}

static void	free_textures_hand(t_game *game, void *mlx)
{
	int		i;

	i = -1;
	while (++i < 3)
		if (game->tex_weapon[i].img_ptr && game->tex_weapon[i].data)
			mlx_destroy_image(mlx, game->tex_weapon[i].img_ptr);
	i = -1;
	while (++i < 2)
		if (game->tex_hand[i].img_ptr && game->tex_hand[i].data)
			mlx_destroy_image(mlx, game->tex_hand[i].img_ptr);
	return ;
}

static void	exit_game_cont(t_game *game, void *mlx)
{
	if (game->img.img_ptr && game->img.data)
		mlx_destroy_image(mlx, game->img.img_ptr);
	if (game->sword.img_ptr && game->sword.data)
		mlx_destroy_image(mlx, game->sword.img_ptr);
	if (game->enemy.img.img_ptr && game->enemy.img.data)
		mlx_destroy_image(mlx, game->enemy.img.img_ptr);
	if (game->item.img_ptr && game->item.data)
		mlx_destroy_image(mlx, game->item.img_ptr);
	if (game->items)
		free(game->items);
	if (game->map)
		free(game->map);
	if (game->sprite_order)
		free(game->sprite_order);
	if (game->sprite_dis)
		free(game->sprite_dis);
	if (game->z_buffer)
		free(game->z_buffer);
	if (game->win_ptr)
		mlx_destroy_window(mlx, game->win_ptr);
	return ;
}

int			exit_game(t_game *game)
{
	void	*mlx;
	int		i;

	mlx = game->mlx_ptr;
	free_textures_walls(game, mlx);
	free_textures_floor_ceiling(game, mlx);
	free_textures_hand(game, mlx);
	i = -1;
	while (++i < 2)
		if (game->life[i].img_ptr)
			mlx_destroy_image(mlx, game->life[i].img_ptr);
	i = -1;
	while (++i < game->m_height)
		if ((game->map)[i])
			free((game->map)[i]);
	exit_game_cont(game, mlx);
	printf("exit game.\n");
	exit(0);
}
