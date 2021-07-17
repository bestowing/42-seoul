/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:46:03 by chelee            #+#    #+#             */
/*   Updated: 2021/02/19 11:46:11 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*b_char;
	int				i;

	b_char = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b_char[i] = (unsigned char)c;
		i++;
	}
	return (b_char);
}
