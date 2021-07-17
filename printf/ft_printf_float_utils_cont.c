/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float_utils_cont.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:32:46 by chelee            #+#    #+#             */
/*   Updated: 2020/11/06 02:28:30 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_handle_rounding(char *f, int curr, int next)
{
	int	i;
	int	flag;

	flag = 0;
	if (f[next] == '5')
	{
		i = 1;
		flag = 1;
		while (f[next + i] && f[next + i] == '0')
			i++;
		if (f[next + i] && f[next + i] != '0')
		{
			flag = 1;
			return (flag);
		}
		if (flag && (f[curr] - '0') % 2 == 0)
			flag = 0;
	}
	else if (f[next] > '5')
		flag = 1;
	return (flag);
}

int			ft_add_rounding(char **f, int idx)
{
	int		flag;
	char	c;

	flag = FALSE;
	c = (*f)[idx];
	c += 1;
	if (c > '9')
	{
		c = '0';
		flag = TRUE;
	}
	(*f)[idx] = c;
	return (flag);
}

static char	*make_rounding(char *f, int *e)
{
	char	*result;
	int		len;
	int		i;

	len = ft_strlen(f);
	if (e != NULL)
		*e += 1;
	if (!(result = malloc(len + 2)))
	{
		free(f);
		return (result);
	}
	result[len + 1] = 0;
	result[0] = '1';
	i = 1;
	while (i < len + 1)
	{
		result[i] = f[i - 1];
		i++;
	}
	free(f);
	return (result);
}

char		*round_fraction(char *f, int point_idx, int precision, int *e)
{
	int		flag;
	int		curr;
	int		next;

	if (precision < 0)
		return (f);
	curr = point_idx + precision;
	next = curr + 1;
	if (f[curr] == '.')
		curr -= 1;
	flag = ft_handle_rounding(f, curr, next);
	f[next] = 0;
	while (flag && curr >= 0)
	{
		flag = ft_add_rounding(&f, curr--);
		if (f[curr] == '.')
			curr--;
	}
	if (flag)
		f = make_rounding(f, e);
	return (f);
}

char		*re_normalize(char *f)
{
	char	tmp;

	tmp = f[1];
	f[1] = f[2];
	f[2] = tmp;
	f[ft_strlen(f) - 1] = 0;
	return (f);
}
