/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float_utils_cont2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 03:05:37 by chelee            #+#    #+#             */
/*   Updated: 2020/11/06 03:08:44 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_handle_precision(t_data d, char *f, int *e)
{
	int	len;
	int	point_idx;
	int	float_len;
	int	precision;

	len = ft_strlen(f);
	point_idx = find_chr(f);
	float_len = len - point_idx - 1;
	precision = d.precision;
	if (precision > float_len)
		f = expand_fraction(f, point_idx, precision);
	else
		f = round_fraction(f, point_idx, precision, e);
	return (f);
}
