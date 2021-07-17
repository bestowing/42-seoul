/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f_type_cont.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:53:52 by chelee            #+#    #+#             */
/*   Updated: 2020/11/05 21:01:31 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_content(char *f, t_data d, int content)
{
	if (d.sign)
	{
		content--;
		if (d.flag_zero == 0)
			write(1, &(d.sign), 1);
	}
	write(1, f, content);
}

int			print_f(t_data d, char *f)
{
	int	content;

	manage_fraction(&f, d.flag_hash);
	content = ft_strlen(f);
	if (d.sign)
		content++;
	if (d.sign && d.flag_zero == 1)
		write(1, &(d.sign), 1);
	if (d.width > content && !(d.flag_minus))
		print_offset(d.width - content, d.flag_zero);
	print_content(f, d, content);
	if (d.width > content && d.flag_minus)
		print_offset(d.width - content, d.flag_zero);
	if (d.width > content)
		content = d.width;
	return (content);
}

int			print_special(t_data d, char *f)
{
	int	content;

	content = 3;
	if (d.sign)
		content++;
	if (d.sign && d.flag_zero == 1)
		write(1, &(d.sign), 1);
	if (d.width > content && !(d.flag_minus))
		print_offset(d.width - content, d.flag_zero);
	if (d.sign && d.flag_zero == 0)
		write(1, &(d.sign), 1);
	write(1, f, 3);
	if (d.width > content && d.flag_minus)
		print_offset(d.width - content, d.flag_zero);
	if (d.width > content)
		content = d.width;
	return (content);
}
