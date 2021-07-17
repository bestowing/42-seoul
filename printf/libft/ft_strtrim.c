/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:01:47 by chelee            #+#    #+#             */
/*   Updated: 2020/09/30 23:05:58 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const *set, char c)
{
	size_t i;

	if (set == 0)
		return (0);
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*setting(char const *s1, size_t start, size_t end)
{
	char	*result;
	size_t	len;
	size_t	i;

	result = 0;
	len = end + 2 > start ? end - start + 2 : 1;
	i = 0;
	if ((result = malloc(len)) == 0)
		return (0);
	while (start + i <= end)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == 0)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	if (end != 0)
		end--;
	while (s1[start] && is_in_set(set, s1[start]))
		start++;
	while (end != 0 && is_in_set(set, s1[end]))
		end--;
	return (setting(s1, start, end));
}
