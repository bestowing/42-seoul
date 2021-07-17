/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 07:11:38 by chelee            #+#    #+#             */
/*   Updated: 2020/10/01 22:14:26 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_byte;
	const char	*src_byte;
	size_t		i;

	if (dst == NULL && src == NULL)
		return (dst);
	dst_byte = (char *)dst;
	src_byte = src;
	i = 0;
	while (i < n)
	{
		dst_byte[i] = src_byte[i];
		i++;
	}
	return (dst);
}
