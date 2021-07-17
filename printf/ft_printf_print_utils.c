/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:47:34 by chelee            #+#    #+#             */
/*   Updated: 2020/11/04 22:33:56 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putullnbr_fd(unsigned long long n, int base, int upper)
{
	char	c;

	if (n >= (unsigned long long)base)
		ft_putullnbr_fd(n / base, base, upper);
	c = (n % base);
	if (c > 9)
	{
		if (upper)
			c += ('A' - 10);
		else
			c += ('a' - 10);
	}
	else
		c += '0';
	write(1, &c, 1);
	return ;
}

void	ft_putllnbr_fd(long long n, int base, int upper)
{
	char	c;

	if (n >= (long long)base)
		ft_putllnbr_fd(n / base, base, upper);
	c = (n % base);
	if (c > 9)
	{
		if (upper)
			c += ('A' - 10);
		else
			c += ('a' - 10);
	}
	else
		c += '0';
	write(1, &c, 1);
	return ;
}

void	print_offset(int cnt, int flag_zero)
{
	char	c;
	int		i;

	c = ' ';
	if (flag_zero)
		c = '0';
	i = 0;
	while (i < cnt)
	{
		write(1, &c, 1);
		i++;
	}
	return ;
}
