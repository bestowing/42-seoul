/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 06:59:00 by chelee            #+#    #+#             */
/*   Updated: 2020/09/30 16:14:54 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s_bytes;
	size_t	i;

	if (n == 0)
		return ;
	s_bytes = (char *)s;
	i = 0;
	while (i < n)
	{
		s_bytes[i] = 0;
		i++;
	}
	return ;
}
