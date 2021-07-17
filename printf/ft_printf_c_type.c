/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 19:40:17 by chelee            #+#    #+#             */
/*   Updated: 2020/11/06 14:20:56 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_c(t_data d, unsigned char c)
{
	int	content;
	int	size;

	content = 1;
	size = content;
	if (d.width > content)
		size = d.width;
	if (d.width > content && !(d.flag_minus))
		print_offset(d.width - content, d.flag_zero);
	write(1, &c, 1);
	if (d.width > content && d.flag_minus)
		print_offset(d.width - content, d.flag_zero);
	return (size);
}

static int	print_lc(t_data d, wchar_t c)
{
	int	content;
	int	size;

	content = -1;
	if (c < 128)
		content = 1;
	else if (c < 2048)
		content = 2;
	else if (c < 65536)
		content = 3;
	else if (c < 2097152)
		content = 4;
	if (d.width > content && !(d.flag_minus))
		print_offset(d.width - content, d.flag_zero);
	size = ft_putunichar(c);
	if (d.width > content && d.flag_minus)
		print_offset(d.width - content, d.flag_zero);
	if (d.width > content)
		size = d.width;
	return (size);
}

int			handle_c_type(va_list ap, t_data d)
{
	int	result;

	if (d.length == 'l')
		result = print_lc(d, (wchar_t)va_arg(ap, wchar_t));
	else
		result = print_c(d, (unsigned char)va_arg(ap, int));
	return (result);
}
