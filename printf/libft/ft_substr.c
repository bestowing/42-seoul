/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 21:25:50 by chelee            #+#    #+#             */
/*   Updated: 2020/10/01 23:28:34 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*allo_str(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	if (start < ft_strlen(s))
	{
		while (j++ < len && s[start + i])
			i++;
	}
	if ((substr = malloc(i + 1)) == 0)
		return (NULL);
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	size_t			j;

	if (s == NULL)
		return (NULL);
	if (!(substr = allo_str(s, start, len)))
		return (NULL);
	i = 0;
	j = 0;
	if (start < ft_strlen(s))
	{
		while (j++ < len && s[start + i])
		{
			substr[i] = s[start + i];
			i++;
		}
	}
	substr[i] = 0;
	return (substr);
}
