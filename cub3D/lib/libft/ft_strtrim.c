/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:41:49 by chelee            #+#    #+#             */
/*   Updated: 2021/02/11 14:47:07 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*setting(char *s1, int start, int end)
{
	char	*result;
	int		len;
	int		i;

	result = 0;
	len = end - start + 1;
	if ((result = malloc(len + 1)) != NULL)
	{
		i = -1;
		while (++i + start <= end)
			result[i] = s1[start + i];
		result[len] = 0;
	}
	return (result);
}

char		*ft_strtrim(char *s1)
{
	char *ret;
	int	start;
	int	end;

	ret = NULL;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && s1[start] == ' ')
		start++;
	if (start != end)
	{
		if (end != 0)
			end--;
		while (end > 0 && s1[end] == ' ')
			end--;
		ret = setting(s1, start, end);
	}
	free(s1);
	return (ret);
}
