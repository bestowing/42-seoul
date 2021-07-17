/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_e_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:46:43 by chelee            #+#    #+#             */
/*   Updated: 2020/11/06 00:06:54 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_result(char *f, int size, int nbr)
{
	char	*result;
	int		i;

	if (!(result = malloc(size + 1)))
	{
		free(f);
		return (NULL);
	}
	result[0] = f[nbr];
	result[1] = '.';
	i = 2;
	while (i < size)
	{
		++nbr;
		if (f[nbr] == '.')
			continue;
		result[i] = f[nbr];
		i++;
	}
	result[size] = 0;
	free(f);
	return (result);
}

static char	*normalize(char *f, int *e)
{
	int		point;
	int		nbr;
	int		size;

	if (f[0] != '0' && f[1] == '.')
	{
		*e = 0;
		return (f);
	}
	point = find_chr(f);
	nbr = find_valid_nbr(f);
	if (nbr == -1)
	{
		*e = 0;
		return (f);
	}
	if (point > nbr)
		*e = point - nbr - 1;
	else
		*e = point - nbr;
	size = ft_strlen(f + nbr) + 1;
	if (point > nbr)
		size--;
	return (make_result(f, size, nbr));
}

static char	*handle_precision(t_data d, char *f, int *e)
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
		f = round_fraction(f, point_idx, precision, e);
	return (f);
}

int			handle_e_type(va_list ap, t_data d)
{
	double	val;
	char	*double_str;
	int		result;
	int		e;

	val = (double)va_arg(ap, double);
	set_double_sign(&d, val);
	if (!(double_str = ft_ftoa(val)))
		return (ERROR);
	if (double_str[0] == 'i' || double_str[0] == 'n')
		result = print_special(d, double_str);
	else
	{
		if (!(double_str = normalize(double_str, &e)))
			return (ERROR);
		if (!(double_str = handle_precision(d, double_str, &e)))
			return (ERROR);
		if (double_str[1] != '.')
			double_str = re_normalize(double_str);
		result = print_e(d, double_str, e);
	}
	free(double_str);
	return (result);
}
