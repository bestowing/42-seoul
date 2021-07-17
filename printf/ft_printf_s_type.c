/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 19:41:07 by chelee            #+#    #+#             */
/*   Updated: 2020/11/06 15:39:02 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_s(t_data d, char *s)
{
	int	content;
	int	size;

	if (s == NULL)
	{
		content = 6;
		s = "(null)";
	}
	else
		content = ft_strlen(s);
	if (d.precision > -1 && d.precision < content)
		content = d.precision;
	size = content;
	if (d.width > content)
		size = d.width;
	if (d.width > content && !(d.flag_minus))
		print_offset(d.width - content, d.flag_zero);
	write(1, s, content);
	if (d.width > content && d.flag_minus)
		print_offset(d.width - content, d.flag_zero);
	return (size);
}

static int	ft_cnt_unilen(wchar_t c)
{
	int	len;

	len = -1;
	if (c < 128)
		len = 1;
	else if (c < 2048)
		len = 2;
	else if (c < 65536)
		len = 3;
	else if (c < 2097152)
		len = 4;
	return (len);
}

static int	print_ls(t_data d, wchar_t *s)
{
	int		content;
	int		i;

	content = 0;
	i = 0;
	if (s == NULL)
		return (print_s(d, "(null)"));
	while (s[i])
		content += ft_cnt_unilen(s[i++]);
	if (d.width > content && !(d.flag_minus))
		print_offset(d.width - content, d.flag_zero);
	i = 0;
	while (s[i])
		ft_putunichar(s[i++]);
	if (d.width > content && d.flag_minus)
		print_offset(d.width - content, d.flag_zero);
	if (d.width > content)
		content = d.width;
	return (content);
}

int			handle_s_type(va_list ap, t_data d)
{
	int result;

	if (d.length == 'l')
		result = print_ls(d, (wchar_t *)va_arg(ap, wchar_t *));
	else
		result = print_s(d, (char *)va_arg(ap, char *));
	return (result);
}
