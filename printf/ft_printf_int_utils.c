/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 08:15:08 by chelee            #+#    #+#             */
/*   Updated: 2020/11/04 23:40:56 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			cnt_nbr_size(long long n, int base, int is_unsigned)
{
	int					i;
	unsigned long long	un;

	i = 0;
	if (n == 0)
		return (1);
	if (is_unsigned)
	{
		un = n;
		while (un > 0)
		{
			un /= base;
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n /= base;
			i++;
		}
	}
	return (i);
}

static void	get_value_cont(va_list ap, t_data d, long long *v, int is_unsigned)
{
	if (d.length == 'l')
	{
		if (is_unsigned)
			*v = (unsigned long)va_arg(ap, long);
		else
			*v = va_arg(ap, long);
	}
	else
	{
		if (is_unsigned)
			*v = (unsigned long long)va_arg(ap, long long);
		else
			*v = va_arg(ap, long long);
	}
	return ;
}

void		get_value(va_list ap, t_data d, long long *v, int is_unsigned)
{
	if (d.length == 0)
	{
		if (is_unsigned)
			*v = (unsigned int)va_arg(ap, int);
		else
			*v = (int)va_arg(ap, int);
	}
	else if (d.length == 'h')
	{
		if (is_unsigned)
			*v = (unsigned short)va_arg(ap, int);
		else
			*v = (short)va_arg(ap, int);
	}
	else if (d.length == 'H')
	{
		if (is_unsigned)
			*v = (unsigned char)va_arg(ap, int);
		else
			*v = (char)va_arg(ap, int);
	}
	else
		get_value_cont(ap, d, v, is_unsigned);
	return ;
}

void		set_sign(t_data *d, long long *value)
{
	if (*value < 0)
	{
		d->sign = '-';
		(*value) *= -1;
	}
	else if (d->flag_plus)
		d->sign = '+';
	else if (d->flag_blank)
		d->sign = ' ';
	else
		d->sign = 0;
	return ;
}
