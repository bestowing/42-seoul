/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing_helper.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:37:27 by chelee            #+#    #+#             */
/*   Updated: 2020/11/03 23:05:28 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char c)
{
	if (c == '-' || c == '0' ||
			c == '+' || c == ' ' || c == '#')
		return (1);
	return (0);
}

int	is_nbr(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_length(char c)
{
	if (c == 'l' || c == 'h')
		return (1);
	return (0);
}

int	is_type_chr(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
	|| c == 'u' || c == 'x' || c == 'X' || c == 'o' || c == '%'
	|| c == 'n' || c == 'f' || c == 'g' || c == 'e')
		return (1);
	return (0);
}
