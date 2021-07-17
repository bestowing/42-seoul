/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 19:41:46 by chelee            #+#    #+#             */
/*   Updated: 2020/11/05 00:36:00 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_content(unsigned long long v, int zero, int precision)
{
	write(1, "0x", 2);
	while (zero > 0)
	{
		write(1, "0", 1);
		zero--;
	}
	if (v == 0)
	{
		if (precision != 0)
			write(1, "0", 1);
	}
	else
		ft_putullnbr_fd(v, 16, 0);
	return ;
}

static int	print_p(t_data d, unsigned long long v)
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
	size = nbr + 2 + zero;
	if (d.width > size && !(d.flag_minus))
		print_offset(d.width - size, d.flag_zero);
	print_content(v, zero, d.precision);
	if (d.width > size && d.flag_minus)
		print_offset(d.width - size, d.flag_zero);
	if (d.width > size)
		size = d.width;
	return (size);
}

int			handle_p_type(va_list ap, t_data d)
{
	int	result;

	result = print_p(d, va_arg(ap, long long));
	return (result);
}
