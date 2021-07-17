/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:54:20 by chelee            #+#    #+#             */
/*   Updated: 2020/10/01 22:17:19 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_byte;
	const unsigned char	*s2_byte;
	size_t				i;

	s1_byte = s1;
	s2_byte = s2;
	i = 0;
	while (i < n && s1_byte[i] == s2_byte[i])
		i++;
	if (i == n)
		return (0);
	return (s1_byte[i] - s2_byte[i]);
}
