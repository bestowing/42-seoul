/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 19:44:23 by chelee            #+#    #+#             */
/*   Updated: 2020/11/05 00:36:33 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_content(unsigned long long v, t_data d, int zero, int upper)
{
	if (d.flag_hash && (d.precision != -1 || d.flag_zero == 0))
	{
		if (upper)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
	while (zero-- > 0)
		write(1, "0", 1);
	if (v == 0)
	{
		if (d.precision != 0)
			write(1, "0", 1);
	}
	else
		ft_putullnbr_fd(v, 16, upper);
	return ;
}

static void	print_sign(t_data d, int upper)
{
	if (d.flag_hash && d.precision == -1 && d.flag_zero == 1)
	{
		if (upper)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
	return ;
}

static int	print_x(t_data d, unsigned long long v, int upper)
{
	int	nbr;
	int	zero;
	int	size;

	nbr = cnt_nbr_size(v, 16, TRUE);
	if (v == 0 && d.precision == 0)
		nbr = 0;
	zero = 0;
	if (nbr < d.precision)
		zero = d.precision - nbr;
	size = nbr + zero;
	if (d.flag_hash)
		size += 2;
	print_sign(d, upper);
	if (d.width > size && !(d.flag_minus))
		print_offset(d.width - size, d.flag_zero);
	print_content(v, d, zero, upper);
	if (d.width > size && d.flag_minus)
		print_offset(d.width - size, d.flag_zero);
	if (d.width > size)
		size = d.width;
	return (size);
}

int			handle_x_type(va_list ap, t_data d)
{
	int			result;
	int			upper;
	long long	val;

	get_value(ap, d, &val, TRUE);
	upper = FALSE;
	if (d.type == 'X')
		upper = TRUE;
	if (d.precision >= 0)
		d.flag_zero = 0;
	if (val == 0)
		d.flag_hash = 0;
	result = print_x(d, val, upper);
	return (result);
}
