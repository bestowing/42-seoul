/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_g_type_cont.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:32:53 by chelee            #+#    #+#             */
/*   Updated: 2020/11/06 02:45:25 by chelee           ###   ########.fr       */
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

int			select_f_type(t_data d, char *f)
{
	int	content;

	manage_fraction(&f, d.flag_hash);
	if (!d.flag_hash)
		handle_trailing_zero(f);
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
