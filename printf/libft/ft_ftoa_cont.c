/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_cont.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:30:51 by chelee            #+#    #+#             */
/*   Updated: 2020/11/05 20:50:07 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_exp(const char *bits)
{
	int	exp;
	int	i;

	exp = 0;
	i = 1;
	while (i <= 11)
	{
		exp *= 2;
		if (bits[i] == '1')
			exp += 1;
		i++;
	}
	return (exp);
}

static void	handle_double_n(int exp, char *bits, char **n)
{
	int	e;
	int	i;

	if (exp == 0)
		e = -1022;
	else
		e = exp - 1023;
	if (e < 0)
	{
		(*n)[0] = '0';
		return ;
	}
	i = 0;
	while (i < e)
	{
		multi_bigint_int(n);
		if (i < 53 && bits[12 + i] == '1')
			add_bigint_int(n);
		i++;
	}
	return ;
}

static int	find_non_zero(char *bits)
{
	int	i;

	i = 0;
	while (bits[i])
	{
		if (bits[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

static char	*handle_special_value(char *bits)
{
	char	*result;

	if (!(result = malloc(4)))
		return (NULL);
	result[3] = 0;
	if (find_non_zero(bits + 13))
	{
		result[0] = 'n';
		result[1] = 'a';
		result[2] = 'n';
	}
	else
	{
		result[0] = 'i';
		result[1] = 'n';
		result[2] = 'f';
	}
	return (result);
}

char		*get_result(char *bits, t_double *d)
{
	char	big_int_f[BIGSIZE];
	int		exp;

	ft_memset(big_int_f, -1, BIGSIZE);
	big_int_f[0] = '1';
	big_int_f[BIGSIZE - 1] = 0;
	exp = get_exp(bits);
	if (exp == 2047)
		return (handle_special_value(bits));
	handle_double_n(exp, bits, &(d->integer));
	handle_double_f(exp, bits, &(d->fraction), big_int_f);
	return (concat_int_frac(d->integer, d->fraction));
}
