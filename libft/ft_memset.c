/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:46:09 by chelee            #+#    #+#             */
/*   Updated: 2020/09/30 11:30:10 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_char;
	size_t			i;

	b_char = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b_char[i] = (unsigned char)c;
		i++;
	}
	return (b_char);
}
