/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:54:57 by chelee            #+#    #+#             */
/*   Updated: 2020/11/04 13:31:23 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_ptr(char *a, char *b, char *c)
{
	if (a != NULL)
		free(a);
	if (b != NULL)
		free(b);
	if (c != NULL)
		free(c);
	return ;
}

static char		*get_bits(t_bits u_bit)
{
	char	*result;
	int		idx;
	int		tmp;
	int		i;
	int		j;

	if (!(result = malloc(64 + 1)))
		return (NULL);
	idx = 0;
	j = 8;
	while (--j >= 0)
	{
		tmp = (int)u_bit.bits[j];
		i = 8;
		while (--i >= 0)
		{
			if (tmp & (1 << i))
				result[idx] = '1';
			else
				result[idx] = '0';
			idx++;
		}
	}
	result[idx] = 0;
	return (result);
}

static int		set_ptr(t_bits u_bit, char **bits, t_double *d)
{
	int result;

	result = 0;
	if (!(*bits = get_bits(u_bit)))
		result = 1;
	if (!(d->integer = malloc(BIGSIZE)))
		result = 1;
	if (!(d->fraction = malloc(BIGSIZE)))
		result = 1;
	if (result)
	{
		free_ptr(d->integer, d->fraction, *bits);
		return (0);
	}
	ft_memset(d->integer, -1, BIGSIZE);
	d->integer[BIGSIZE - 1] = 0;
	d->integer[0] = '1';
	ft_memset(d->fraction, -1, BIGSIZE);
	d->fraction[BIGSIZE - 1] = 0;
	d->fraction[0] = '0';
	return (1);
}

char			*ft_ftoa(double f)
{
	t_bits		u_bit;
	char		*bits;
	char		*result;
	t_double	d;

	u_bit.value = f;
	if (!(set_ptr(u_bit, &bits, &d)))
		return (NULL);
	result = get_result(bits, &d);
	free_ptr(bits, d.integer, d.fraction);
	return (result);
}
