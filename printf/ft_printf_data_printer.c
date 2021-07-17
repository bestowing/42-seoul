/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_data_printer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:34:39 by chelee            #+#    #+#             */
/*   Updated: 2020/11/04 23:49:21 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	classify_type_bonus(va_list ap, t_data d, int len)
{
	if (d.type == 'n')
		return (handle_n_type(ap, d, len));
	else if (d.type == 'f')
		return (handle_f_type(ap, d));
	else if (d.type == 'e')
		return (handle_e_type(ap, d));
	return (handle_g_type(ap, d));
}

static int	classify_type(va_list ap, t_data d, int len)
{
	if (d.type == 'c')
		return (handle_c_type(ap, d));
	else if (d.type == 's')
		return (handle_s_type(ap, d));
	else if (d.type == 'p')
		return (handle_p_type(ap, d));
	else if (d.type == 'd' || d.type == 'i')
		return (handle_d_type(ap, d));
	else if (d.type == 'u')
		return (handle_u_type(ap, d));
	else if (d.type == 'x' || d.type == 'X')
		return (handle_x_type(ap, d));
	else if (d.type == 'o')
		return (handle_o_type(ap, d));
	else if (d.type == '%')
		return (handle_percent_type(d));
	return (classify_type_bonus(ap, d, len));
}

int			print_data(va_list ap, t_data d, int len)
{
	if (d.flag_minus && d.flag_zero)
		d.flag_zero = 0;
	if (d.flag_plus && d.flag_blank)
		d.flag_blank = 0;
	return (classify_type(ap, d, len));
}
