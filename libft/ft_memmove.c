/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 07:36:20 by chelee            #+#    #+#             */
/*   Updated: 2020/10/01 23:56:43 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_byte;
	const char	*src_byte;
	size_t		i;

	if ((dst == NULL && src == NULL) || len == 0)
		return (dst);
	dst_byte = dst;
	src_byte = src;
	i = 0;
	if (dst > src)
	{
		while (len--)
			dst_byte[len] = src_byte[len];
		dst_byte[0] = src_byte[0];
	}
	else
		while (i++ < len)
			dst_byte[i - 1] = src_byte[i - 1];
	return (dst);
}
