/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_fraction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:56:52 by chelee            #+#    #+#             */
/*   Updated: 2020/10/26 20:43:32 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		denormalized(int e, char *bits, char **fraction, char *big_int)
{
	int i;

	i = e;
	while (i < 0)
	{
		multi_bigint(big_int);
		i++;
	}
	while (i < 52)
	{
		multi_bigint(big_int);
		if (bits[12 + i] == '1')
			add_bigint(fraction, big_int);
		i++;
	}
	return ;
}

static void		normalized(int e, char *bits, char **fraction, char *big_int)
{
	int i;
	int tmp;

	tmp = e;
	if (e < 0)
		i = 0;
	else
		i = e;
	while (tmp < 0)
	{
		multi_bigint(big_int);
		if (tmp == -1)
			add_bigint(fraction, big_int);
		tmp++;
	}
	while (i < 52)
	{
		multi_bigint(big_int);
		if (12 + i >= 12 && 12 + i < 64)
			if (bits[12 + i] == '1')
				add_bigint(fraction, big_int);
		i++;
	}
	return ;
}

void			handle_double_f(int exp, char *bits, char **f, char *big_int)
{
	if (exp == 0)
		denormalized(-1022, bits, f, big_int);
	else
		normalized(exp - 1023, bits, f, big_int);
	return ;
}
