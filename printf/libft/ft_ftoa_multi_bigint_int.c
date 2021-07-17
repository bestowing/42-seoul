/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_multi_bigint_int.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:27:10 by chelee            #+#    #+#             */
/*   Updated: 2020/10/26 21:14:23 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	multi_bigint_int_round(char **nbr, int prev, int i)
{
	int tmp;

	while (prev != 0)
	{
		tmp = (*nbr)[i] == -1 ? 0 : (*nbr)[i] - '0';
		tmp += prev;
		if (tmp > 10)
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

void	multi_bigint_int(char **nbr)
{
	int	i;
	int tmp;
	int prev;

	prev = 0;
	i = 0;
	while ((*nbr)[i] > 0)
	{
		tmp = (*nbr)[i] - '0';
		tmp *= 2;
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
	multi_bigint_int_round(nbr, prev, i);
	return ;
}
