/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 07:28:18 by chelee            #+#    #+#             */
/*   Updated: 2020/09/30 11:36:29 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dst_byte;
	const char		*src_byte;
	unsigned char	c_cmp;
	size_t			i;

	dst_byte = (char *)dst;
	src_byte = src;
	i = 0;
	while (i < n)
	{
		c_cmp = src_byte[i];
		dst_byte[i] = c_cmp;
		i++;
		if (c_cmp == (unsigned char)c)
			return (dst + i);
	}
	return (0);
}
