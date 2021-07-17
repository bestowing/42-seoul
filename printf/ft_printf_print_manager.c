/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_manager.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 00:39:23 by chelee            #+#    #+#             */
/*   Updated: 2020/11/01 21:04:50 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			manage_print(const char *format, va_list ap)
{
	int i;
	int print_len;
	int total_len;

	i = 0;
	total_len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if ((print_len = parse_data(format, ap, &i, total_len)) == ERROR)
				return (ERROR);
			total_len += print_len;
		}
		else
		{
			write(1, format + i++, 1);
			total_len++;
		}
	}
	return (total_len);
}
