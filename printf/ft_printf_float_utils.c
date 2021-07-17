/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 02:20:36 by chelee            #+#    #+#             */
/*   Updated: 2020/11/05 15:58:34 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*expand_fraction(char *f, int point_idx, int precision)
{
	char	*result;
	int		i;

	if (!(result = malloc(point_idx + precision + 2)))
	{
		free(f);
		return (NULL);
	}
	ft_memset(result, '0', point_idx + precision + 1);
	result[point_idx + precision + 1] = 0;
	i = 0;
	while (f[i] && f[i] != '.')
	{
		result[i] = f[i];
		i++;
	}
	result[i++] = '.';
	while (f[i])
	{
		result[i] = f[i];
		i++;
	}
	free(f);
	return (result);
}

void	set_double_sign(t_data *d, double v)
{
	if (ft_isnegative_double(v))
	{
		d->sign = '-';
		v *= -1;
	}
	else if (d->flag_plus)
		d->sign = '+';
	else if (d->flag_blank)
		d->sign = ' ';
	return ;
}

int		find_chr(char *f)
{
	int	i;

	i = 0;
	while (f[i])
	{
		if (f[i] == '.')
			return (i);
		i++;
	}
	return (-1);
}

int		find_valid_nbr(char *f)
{
	int	i;

	i = 0;
	while (f[i])
	{
		if (f[i] > '0' && f[i] <= '9')
			return (i);
		i++;
	}
	return (-1);
}

void	manage_fraction(char **f, int flag_hash)
{
	int	idx;

	idx = ft_strlen(*f);
	if ((*f)[idx - 1] == '.' && flag_hash == 0)
		(*f)[idx - 1] = 0;
	return ;
}
