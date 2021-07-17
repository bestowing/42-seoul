/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_g_type_cont2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:11:14 by chelee            #+#    #+#             */
/*   Updated: 2020/11/05 23:37:33 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cnt_exp(int e)
{
	int	len;

	len = 2;
	if (e < 0)
		e *= -1;
	if (e < 100)
		len += 2;
	else
	{
		while (e > 0)
		{
			e /= 10;
			len++;
		}
	}
	return (len);
}

static void	print_exp(int e)
{
	if (e < 0)
		e *= -1;
	if (e < 100)
	{
		ft_putnbr_fd(e / 10, 1);
		ft_putnbr_fd(e % 10, 1);
	}
	else
		ft_putnbr_fd(e, 1);
	return ;
}

static void	print_content(char *f, t_data d, int content, int e)
{
	if (d.sign)
	{
		content--;
		if (d.flag_zero == 0)
			write(1, &(d.sign), 1);
	}
	write(1, f, content);
	write(1, "e", 1);
	if (e >= 0)
		write(1, "+", 1);
	else
		write(1, "-", 1);
	print_exp(e);
	return ;
}

static void	handle_trailing_zero(char *f)
{
	int	idx;

	idx = ft_strlen(f) - 1;
	while (idx > 0 && f[idx] == '0')
		idx--;
	if (f[idx] == '.')
		f[idx] = 0;
	else if (f[idx + 1] == '0')
		f[idx + 1] = 0;
	return ;
}

int			select_e_type(t_data d, char *f, int e)
{
	int	content;
	int	exp;

	manage_fraction(&f, d.flag_hash);
	if (!d.flag_hash)
		handle_trailing_zero(f);
	content = ft_strlen(f);
	exp = cnt_exp(e);
	if (d.sign)
		content++;
	if (d.sign && d.flag_zero == 1)
		write(1, &(d.sign), 1);
	if (d.width > content + exp && !(d.flag_minus))
		print_offset(d.width - content - exp, d.flag_zero);
	print_content(f, d, content, e);
	if (d.width > content + exp && d.flag_minus)
		print_offset(d.width - content - exp, d.flag_zero);
	if (d.width > content + exp)
		content = d.width;
	return (content);
}
