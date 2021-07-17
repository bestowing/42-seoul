/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_g_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:49:38 by chelee            #+#    #+#             */
/*   Updated: 2020/11/06 03:09:12 by chelee           ###   ########.fr       */
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

static int	handle_g_type_cont(t_data d, int e, char *f_style, char *e_style)
{
	int	precision;

	d.precision -= 1;
	e_style = ft_handle_precision(d, e_style, &e);
	if (e_style[1] != '.')
		e_style = re_normalize(e_style);
	d.precision += 1;
	precision = d.precision;
	if (precision == 0)
		precision = 1;
	if (e_style[0] == '0' || (precision > e && e >= -4))
	{
		d.precision = precision - (e + 1);
		free(e_style);
		return (select_f_type(d, ft_handle_precision(d, f_style, NULL)));
	}
	free(f_style);
	d.precision = precision - 1;
	e_style = ft_handle_precision(d, e_style, &e);
	if (e_style[1] != '.')
		e_style = re_normalize(e_style);
	return (select_e_type(d, e_style, e));
}

int			handle_g_type(va_list ap, t_data d)
{
	double	val;
	char	*e_style;
	char	*f_style;
	int		e;

	val = (double)va_arg(ap, double);
	set_double_sign(&d, val);
	if (d.precision == -1)
		d.precision = 6;
	else if (d.precision == 0)
		d.precision = 1;
	if (!(f_style = ft_ftoa(val)))
		return (ERROR);
	if (!(e_style = normalize(f_style, &e)))
	{
		free(f_style);
		return (ERROR);
	}
	if (e_style == f_style && !(e_style = ft_strdup(f_style)))
	{
		free(f_style);
		return (ERROR);
	}
	return (handle_g_type_cont(d, e, f_style, e_style));
}
