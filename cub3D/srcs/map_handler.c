/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 23:37:13 by chelee            #+#    #+#             */
/*   Updated: 2021/02/23 15:50:41 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		**allo_map(int h, int w)
{
	int	**m;
	int	i;

	if (!(m = (int **)ft_calloc(h, sizeof(int *))))
		return (NULL);
	i = -1;
	while (++i < h)
	{
		if (!(m[i] = ft_calloc(w, sizeof(int))))
		{
			free_map(m, h);
			return (NULL);
		}
	}
	return (m);
}

void	free_map(int **map, int height)
{
	int	i;

	i = -1;
	if (map)
	{
		while (++i < height)
		{
			if (!map[i])
				break ;
			free(map[i]);
			map[i] = NULL;
		}
		free(map);
		map = NULL;
	}
	return ;
}
