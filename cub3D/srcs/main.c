/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 01:55:45 by chelee            #+#    #+#             */
/*   Updated: 2021/02/20 03:18:26 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_game_over(t_game *game)
{
	char	*msg;
	char	*msg2;
	char	*msg3;

	msg = "GAME OVER";
	msg2 = "YOUR SCORE: ";
	msg3 = "PRESS ESC TO EXIT.";
	game->player.move_dir = 0;
	game->player.turn_dir = 0;
	game->player.ver_dir = 0;
	game->player.walk_dir = 0;
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		game->s_width / 2 - 3 * ft_strlen(msg),
		game->s_height / 2 - 20, 0xFFFFFF, msg);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		game->s_width / 2 - 3 * ft_strlen(msg2),
		game->s_height / 2, 0xFFFFFF, msg2);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		game->s_width / 2 - 3 * ft_strlen(msg3),
		game->s_height / 2 + 20, 0xFFFFFF, msg3);
	return ;
}

static int	update_game(t_game *game)
{
	if (game->player.life <= 0)
	{
		handle_game_over(game);
		return (0);
	}
	act_player(game);
	if (game->enemy.life > 0)
		act_enemy(game);
	animate_item(game);
	animate_weapon(game);
	render(game);
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->img.img_ptr, 0, 0);
	return (0);
}

static void	start_game(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 0, press_key, game);
	mlx_hook(game->win_ptr, 3, 0, release_key, &(game->player));
	mlx_hook(game->win_ptr, 6, 0, move_mouse, game);
	mlx_hook(game->win_ptr, 17, 0, exit_game, game);
	mlx_loop_hook(game->mlx_ptr, update_game, game);
	mlx_loop(game->mlx_ptr);
	return ;
}

int			main(int argc, char *argv[])
{
	t_game	game;

	if (init_game(&game) == ERROR)
		exit(0);
	if (argc < 2 || argc > 3)
	{
		handle_error("Number of arguments is not two or three.");
		exit(0);
	}
	if (handle_file(&game, argv[1]) == ERROR)
		exit(0);
	if (check_validation(&game, game.player.pos_x, game.player.pos_y) == ERROR)
		exit(0);
	if (set_game(&game) == ERROR)
	{
		handle_error("failed to set game.\n");
		exit_game(&game);
	}
	update_game(&game);
	if (check_parameter(&game, argc, argv) != FALSE)
		exit(0);
	start_game(&game);
	return (0);
}
