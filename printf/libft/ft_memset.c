/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:46:09 by chelee            #+#    #+#             */
/*   Updated: 2020/10/19 04:58:24 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_char;
	size_t			i;

	if (b == NULL)
		return (NULL);
	b_char = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b_char[i] = (unsigned char)c;
		i++;
	}
	return (b_char);
}
