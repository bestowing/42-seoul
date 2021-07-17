/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:32:11 by chelee            #+#    #+#             */
/*   Updated: 2020/11/01 21:11:45 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;

	if (format == NULL)
		return (ERROR);
	va_start(ap, format);
	result = manage_print(format, ap);
	va_end(ap);
	return (result);
}
