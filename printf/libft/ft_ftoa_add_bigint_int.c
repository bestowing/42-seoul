/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_add_bigint_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:22:51 by chelee            #+#    #+#             */
/*   Updated: 2020/10/26 20:29:50 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_bigint_cont(char **nbr, int prev, int i)
{
	int tmp;

	while (prev != 0)
	{
		tmp = (*nbr)[i] == -1 ? 0 : (*nbr)[i] - '0';
		tmp += prev;
		if (tmp >= 10)
		{
			prev = tmp / 10;
			tmp %= 10;
		}
		else
			prev = 0;
		(*nbr)[i] = tmp + '0';
		i++;
	}
	return ;
}

void		add_bigint_int(char **nbr)
{
	int i;
	int tmp;
	int prev;

	i = 0;
	prev = 0;
	tmp = 1;
	tmp += ((*nbr)[i] == -1) ? 0 : (*nbr)[i] - '0';
	tmp += prev;
	if (tmp >= 10)
	{
		prev = tmp / 10;
		tmp %= 10;
	}
	else
		prev = 0;
	(*nbr)[i] = tmp + '0';
	i++;
	add_bigint_cont(nbr, prev, i);
	return ;
}
