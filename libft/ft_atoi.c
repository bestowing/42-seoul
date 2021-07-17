/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:14:17 by chelee            #+#    #+#             */
/*   Updated: 2020/10/02 00:01:01 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
			c == '\r')
		return (1);
	return (0);
}

static int	is_nbr(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

const char	*chk_str(const char *str, int *is_negative)
{
	while (is_white_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*is_negative = 1;
		str++;
	}
	return (str);
}

int			ft_atoi(const char *str)
{
	size_t	i;
	int		is_negative;
	int		result;

	i = 0;
	is_negative = 0;
	result = 0;
	str = chk_str(str, &is_negative);
	while (is_nbr(*str))
	{
		result *= 10;
		result += (*str) - '0';
		i++;
		str++;
	}
	if (i > 19)
	{
		if (is_negative)
			return (0);
		else
			return (-1);
	}
	return (is_negative == 1 ? -result : result);
}
