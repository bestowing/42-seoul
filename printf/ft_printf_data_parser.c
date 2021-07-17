/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_data_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:51:14 by chelee            #+#    #+#             */
/*   Updated: 2020/11/05 00:35:05 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flag(const char *format, int *idx, t_data *d)
{
	int	i;

	i = *idx;
	while (is_flag(format[i]))
	{
		if (format[i] == '-')
			d->flag_minus = 1;
		else if (format[i] == '0')
			d->flag_zero = 1;
		else if (format[i] == '+')
			d->flag_plus = 1;
		else if (format[i] == ' ')
			d->flag_blank = 1;
		else
			d->flag_hash = 1;
		i++;
	}
	*idx = i;
	return ;
}

static void	parse_width(const char *format, va_list ap, int *idx, t_data *d)
{
	int	i;
	int	sum;

	i = *idx;
	if (format[i] == '*')
	{
		d->width = va_arg(ap, int);
		if (d->width == 0)
			d->width = -1;
		else if (d->width < 0)
		{
			d->width *= -1;
			d->flag_minus = 1;
		}
		i++;
	}
	else if (is_nbr(format[i]))
	{
		sum = 0;
		while (is_nbr(format[i]))
			sum = (sum * 10) + format[i++] - '0';
		d->width = sum;
	}
	*idx = i;
	return ;
}

static void	parse_precision(const char *format, va_list ap, int *idx, t_data *d)
{
	int	i;
	int	sum;

	i = *idx;
	if (format[i++] != '.')
		return ;
	d->precision = 0;
	if (format[i] == '*')
	{
		d->precision = va_arg(ap, int);
		if (d->precision < 0)
			d->precision = -1;
		i++;
	}
	else if (is_nbr(format[i]))
	{
		sum = 0;
		while (is_nbr(format[i]))
			sum = (sum * 10) + format[i++] - '0';
		d->precision = sum;
	}
	*idx = i;
	return ;
}

static void	parse_length(const char *format, int *idx, t_data *d)
{
	int	i;

	i = *idx;
	if (format[i] == 'l')
	{
		d->length = 'l';
		if (format[i + 1] == 'l')
		{
			d->length = 'L';
			i++;
		}
		i++;
	}
	else if (format[i] == 'h')
	{
		d->length = 'h';
		if (format[i + 1] == 'h')
		{
			d->length = 'H';
			i++;
		}
		i++;
	}
	*idx = i;
	return ;
}

int			parse_data(const char *format, va_list ap, int *idx, int len)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	data.width = -1;
	data.precision = -1;
	parse_flag(format, idx, &data);
	parse_width(format, ap, idx, &data);
	parse_precision(format, ap, idx, &data);
	parse_length(format, idx, &data);
	data.type = format[(*idx)];
	if (!(is_type_chr(data.type)))
		return (ERROR);
	*idx = *idx + 1;
	return (print_data(ap, data, len));
}
