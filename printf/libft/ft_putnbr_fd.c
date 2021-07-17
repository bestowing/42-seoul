/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:50:33 by chelee            #+#    #+#             */
/*   Updated: 2020/10/01 19:04:38 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_nbr(int n, int fd)
{
	char c;

	c = (n % 10) + '0';
	if (n / 10 > 0)
		put_nbr(n / 10, fd);
	write(fd, &c, 1);
	return ;
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		put_nbr(214748364, fd);
		write(fd, "8", 1);
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		put_nbr(n, fd);
	}
	return ;
}
