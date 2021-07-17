/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:22:36 by chelee            #+#    #+#             */
/*   Updated: 2020/10/01 22:30:10 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	if (dst == NULL || src == NULL)
	{
		if (src == NULL)
			return (0);
		return (ft_strlen(src));
	}
	i = 0;
	while (i + 1 < dstsize && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = 0;
	return (ft_strlen(src));
}
