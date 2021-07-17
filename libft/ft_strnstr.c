/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:37:12 by chelee            #+#    #+#             */
/*   Updated: 2020/10/03 23:21:43 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	int		result;

	i = 0;
	if (little[0] == 0)
		return ((char *)(size_t)big);
	while (i < len)
	{
		j = 0;
		result = 1;
		while (little[j])
		{
			if (i + j >= len || big[i + j] != little[j])
			{
				result = 0;
				break ;
			}
			j++;
		}
		if (result)
			return ((char *)(size_t)big + i);
		i++;
	}
	return (0);
}
