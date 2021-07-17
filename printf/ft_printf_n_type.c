/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_n_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 19:53:58 by chelee            #+#    #+#             */
/*   Updated: 2020/11/03 23:25:57 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_value_cont(t_data d, unsigned long long addr, int len)
{
	long		*long_addr;
	long long	*long_long_addr;

	if (d.length == 'l')
	{
		long_addr = (long *)addr;
		*long_addr = (long)len;
	}
	else
	{
		long_long_addr = (long long *)addr;
		*long_long_addr = (long long)len;
	}
	return ;
}

static void	set_value(t_data d, unsigned long long addr, int len)
{
	int		*int_addr;
	short	*short_addr;
	char	*char_addr;

	short_addr = NULL;
	char_addr = NULL;
	if (d.length == 0)
	{
		int_addr = (int *)addr;
		*int_addr = len;
	}
	else if (d.length == 'h')
	{
		short_addr = (short *)addr;
		*short_addr = (short)len;
	}
	else if (d.length == 'H')
	{
		char_addr = (char *)addr;
		*char_addr = (char)len;
	}
	else
		set_value_cont(d, addr, len);
	return ;
}

int			handle_n_type(va_list ap, t_data d, int len)
{
	unsigned long long	addr;

	addr = (unsigned long long)va_arg(ap, long long);
	set_value(d, addr, len);
	return (0);
}
