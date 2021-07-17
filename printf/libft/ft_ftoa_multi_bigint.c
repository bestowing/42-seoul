/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_multi_bigint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:11:40 by chelee            #+#    #+#             */
/*   Updated: 2020/10/26 20:18:12 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	multi_bigint_round(char *bigint, int prev, int i)
{
	int tmp;

	while (prev != 0)
	{
		tmp = bigint[i] == -1 ? 0 : bigint[i] - '0';
		tmp += prev;
		if (tmp > 10)
		{
			prev = tmp / 10;
			tmp %= 10;
		}
		else
			prev = 0;
		bigint[i] = tmp + '0';
		i++;
	}
	return ;
}

static void	multi_bigint_while(char *bigint)
{
	int	i;
	int prev;
	int	tmp;

	i = 0;
	prev = 0;
	while (bigint[i] != -1)
	{
		tmp = bigint[i] - '0';
		tmp *= 5;
		tmp += prev;
		if (tmp >= 10)
		{
			prev = tmp / 10;
			tmp %= 10;
		}
		else
			prev = 0;
		bigint[i] = tmp + '0';
		i++;
	}
	multi_bigint_round(bigint, prev, i);
	return ;
}

void		multi_bigint(char *bigint)
{
	int	backup;

	backup = 0;
	while (bigint[backup] != -1)
		backup++;
	multi_bigint_while(bigint);
	if (bigint[backup] == -1)
		bigint[backup] = '0';
	return ;
}
