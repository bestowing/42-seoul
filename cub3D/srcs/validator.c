/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 23:13:53 by chelee            #+#    #+#             */
/*   Updated: 2021/02/19 11:53:47 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_dr_dc(int i, int is_init, int is_dr)
{
	static int	dr[4];
	static int	dc[4];

	if (is_init)
	{
		dr[0] = 1;
		dr[1] = -1;
		dr[2] = 0;
		dr[3] = 0;
		dc[0] = 0;
		dc[1] = 0;
		dc[2] = 1;
		dc[3] = -1;
		return (SUCCESS);
	}
	if (is_dr)
		return (dr[i]);
	return (dc[i]);
}

static int	dfs(t_game *game, int r, int c)
{
	int	***visit;
	int	nr;
	int	nc;
	int	i;

	visit = get_visit();
	(*visit)[r][c] = TRUE;
	i = -1;
	while (++i < 4)
	{
		nr = r + get_dr_dc(i, FALSE, TRUE);
		nc = c + get_dr_dc(i, FALSE, FALSE);
		if (nr < 0 || nr >= game->m_height || nc < 0 || nc >= game->m_width)
			return (ERROR);
		if (game->map[nr][nc] == 1)
			continue ;
		if ((*visit)[nr][nc] == TRUE)
			continue ;
		if (dfs(game, nr, nc) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static void	place_weapon(t_game *game)
{
	int	***visit;
	int	i;
	int	j;

	visit = get_visit();
	i = 0;
	while (++i < game->m_height - 1)
	{
		j = 0;
		while (++j < game->m_width - 1)
		{
			if ((*visit)[i][j])
			{
				game->map[i][j] = 3;
				return ;
			}
		}
	}
}

int			check_validation(t_game *game, int pos_x, int pos_y)
{
	int	***visit;
	int	ret;

	if (init_visit(game->m_height, game->m_width) == ERROR)
	{
		free_map(game->map, game->m_height);
		return (handle_error("failed to allocate memory."));
	}
	visit = get_visit();
	get_dr_dc(0, TRUE, 0);
	ret = dfs(game, pos_y, pos_x);
	place_weapon(game);
	destroy_visit(game->m_height);
	if (ret == ERROR)
	{
		free_map(game->map, game->m_height);
		return (handle_error("Map data is invalid."));
	}
	return (ret);
}
