/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_concat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:57:01 by chelee            #+#    #+#             */
/*   Updated: 2020/11/04 14:01:54 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] > 0)
		i++;
	return (i);
}

char		*concat_int_frac(const char *n, const char *f)
{
	char	*result;
	int		len_n;
	int		len_f;
	int		i;

	len_n = cnt_len(n);
	len_f = cnt_len(f) - 1;
	if (!(result = malloc(len_n + len_f + 2)))
		return (NULL);
	result[len_n] = '.';
	result[len_n + len_f + 1] = 0;
	i = 0;
	while ((len_n - i - 1) >= 0)
	{
		result[i] = n[len_n - i - 1];
		i++;
	}
	i = 1;
	while (--len_f >= 0)
		result[len_n + i++] = f[len_f];
	return (result);
}
