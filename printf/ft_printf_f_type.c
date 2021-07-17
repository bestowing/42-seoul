/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:50:43 by chelee            #+#    #+#             */
/*   Updated: 2020/11/05 22:52:39 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_precision(t_data d, char *f)
{
	int	len;
	int	point_idx;
	int	float_len;
	int	precision;

	len = ft_strlen(f);
	point_idx = find_chr(f);
	float_len = len - point_idx - 1;
	precision = d.precision;
	if (precision == -1)
		precision = 6;
	if (precision > float_len)
		f = expand_fraction(f, point_idx, precision);
	else
		f = round_fraction(f, point_idx, precision, NULL);
	return (f);
}

int			handle_f_type(va_list ap, t_data d)
{
	double	val;
	char	*double_str;
	int		result;

	val = (double)va_arg(ap, double);
	set_double_sign(&d, val);
	if (!(double_str = ft_ftoa(val)))
		return (ERROR);
	if (double_str[0] == 'i' || double_str[0] == 'n')
		result = print_special(d, double_str);
	else
	{
		if (!(double_str = handle_precision(d, double_str)))
			return (ERROR);
		result = print_f(d, double_str);
	}
	free(double_str);
	return (result);
}
