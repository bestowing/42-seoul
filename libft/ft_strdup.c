/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:07:06 by chelee            #+#    #+#             */
/*   Updated: 2020/10/01 23:04:17 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	result = malloc(len + 1);
	if (result == NULL)
		return (result);
	while (i < len)
	{
		result[i] = s1[i];
		i++;
	}
	result[len] = 0;
	return (result);
}
