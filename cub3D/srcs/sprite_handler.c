/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 09:26:55 by chelee            #+#    #+#             */
/*   Updated: 2021/02/19 12:23:21 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	animate_weapon(t_game *game)
{
	t_item	weapon;

	weapon = game->weapon;
	if (weapon.life == 0)
		return ;
	if (weapon.move_dir == 1)
		game->weapon.pos_z += I_M_SPEED;
	else
		game->weapon.pos_z -= I_M_SPEED;
	if (weapon.pos_z <= -96.0)
		game->weapon.move_dir = +1;
	else if (weapon.pos_z >= 0.0)
		game->weapon.move_dir = -1;
	return ;
}

void	animate_item(t_game *game)
{
	t_item	item;
	int		i;

	i = -1;
	while (++i < game->item_size)
	{
		item = game->items[i];
		if (item.life <= 0)
			return ;
		if (item.move_dir == 1)
			game->items[i].pos_z += I_M_SPEED;
		else
			game->items[i].pos_z -= I_M_SPEED;
		if (item.pos_z <= -96.0)
			game->items[i].move_dir = +1;
		else if (item.pos_z >= 0.0)
			game->items[i].move_dir = -1;
	}
	return ;
}
