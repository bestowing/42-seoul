/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 21:50:41 by chelee            #+#    #+#             */
/*   Updated: 2020/10/01 23:31:00 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	result = 0;
	s1_len = s1 != NULL ? ft_strlen(s1) : 0;
	s2_len = s2 != NULL ? ft_strlen(s2) : 0;
	i = 0;
	if ((result = malloc(s1_len + s2_len + 1)) == 0)
		return (NULL);
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		result[s1_len + i] = s2[i];
		i++;
	}
	result[s1_len + i] = 0;
	return (result);
}
