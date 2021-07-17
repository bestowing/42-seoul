/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_cont.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 00:01:54 by chelee            #+#    #+#             */
/*   Updated: 2021/02/19 11:55:51 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		***get_visit(void)
{
	static int	**visit;

	return (&visit);
}

void	destroy_visit(int h)
{
	int	***visit;
	int	i;

	visit = get_visit();
	i = -1;
	while (++i < h)
	{
		if ((*visit)[i] != NULL)
			free((*visit)[i]);
	}
	free(*visit);
	return ;
}

int		init_visit(int h, int w)
{
	int	***visit;
	int	i;

	visit = get_visit();
	(*visit) = (int **)ft_calloc(h, sizeof(int *));
	if (*visit == NULL)
		return (ERROR);
	i = -1;
	while (++i < h)
		(*visit)[i] = (int *)ft_calloc(w, sizeof(int));
	i = -1;
	while (++i < h)
	{
		if ((*visit)[i] == NULL)
		{
			destroy_visit(h);
			return (ERROR);
		}
	}
	return (SUCCESS);
}
