/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:51:46 by chelee            #+#    #+#             */
/*   Updated: 2020/10/01 00:59:46 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char		*set_result(char *result, int n, size_t len)
{
	result[len--] = 0;
	if (n == 0)
		result[0] = '0';
	while (n > 0)
	{
		result[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}

char			*ft_itoa(int n)
{
	char	*result;
	size_t	len;
	int		is_negative;
	int		is_max;

	is_negative = 0;
	is_max = n == -2147483648 ? 1 : 0;
	if (n == -2147483648)
		n++;
	if (n < 0)
	{
		n *= -1;
		is_negative = 1;
	}
	len = is_negative ? get_size(n) + 1 : get_size(n);
	if ((result = malloc(len + 1)) == 0)
		return (0);
	if (is_negative)
		result[0] = '-';
	result = set_result(result, n, len);
	if (is_max)
		result[10] = '8';
	return (result);
}
