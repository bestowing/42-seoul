/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 08:04:15 by chelee            #+#    #+#             */
/*   Updated: 2020/11/04 23:42:19 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_percent(t_data d)
{
	int	content;
	int	size;

	content = 1;
	size = content;
	if (d.width > content)
		size = d.width;
	if (d.width > content && !(d.flag_minus))
		print_offset(d.width - content, d.flag_zero);
	write(1, "%%", 1);
	if (d.width > content && d.flag_minus)
		print_offset(d.width - content, d.flag_zero);
	return (size);
}

int			handle_percent_type(t_data d)
{
	int	result;

	result = print_percent(d);
	return (result);
}
