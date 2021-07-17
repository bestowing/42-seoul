/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:21:44 by chelee            #+#    #+#             */
/*   Updated: 2020/11/05 00:36:40 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_content(unsigned long long v, t_data d, int zero)
{
	if (d.flag_hash && (d.precision != -1 || d.flag_zero == 0))
		write(1, "0", 1);
	while (zero-- > 0)
		write(1, "0", 1);
	if (v == 0)
	{
		if (d.precision != 0)
			write(1, "0", 1);
	}
	else
		ft_putullnbr_fd(v, 8, FALSE);
	return ;
}

static int	print_o(t_data d, unsigned long long v)
{
	int nbr;
	int zero;
	int size;

	nbr = cnt_nbr_size(v, 8, TRUE);
	if (v == 0 && d.precision == 0)
		nbr = 0;
	zero = 0;
	if (nbr < d.precision)
		zero = d.precision - nbr;
	size = nbr + zero;
	if (d.flag_hash)
		size++;
	if (d.flag_hash && d.precision == -1 && d.flag_zero == 1)
		write(1, "0", 1);
	if (d.width > size && !(d.flag_minus))
		print_offset(d.width - size, d.flag_zero);
	print_content(v, d, zero);
	if (d.width > size && d.flag_minus)
		print_offset(d.width - size, d.flag_zero);
	if (d.width > size)
		size = d.width;
	return (size);
}

int			handle_o_type(va_list ap, t_data d)
{
	int			result;
	long long	val;

	get_value(ap, d, &val, TRUE);
	if (d.precision >= 0)
		d.flag_zero = 0;
	if (val == 0)
		d.flag_hash = 0;
	result = print_o(d, val);
	return (result);
}
