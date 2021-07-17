/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:35:58 by chelee            #+#    #+#             */
/*   Updated: 2020/09/29 20:45:52 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_byte;
	void				*result;
	size_t				i;

	s_byte = s;
	result = 0;
	i = 0;
	while (i < n)
	{
		if (s_byte[i] == (unsigned char)c)
			return ((unsigned char *)(size_t)s_byte + i);
		i++;
	}
	return (result);
}
