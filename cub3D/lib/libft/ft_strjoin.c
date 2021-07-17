/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:48:37 by chelee            #+#    #+#             */
/*   Updated: 2021/02/11 21:44:27 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_str(char *s1, char *s2, int len1)
{
	char	*ret;
	int		len2;
	int		i;

	len2 = ft_strlen(s2);
	if (!(ret = malloc(len1 + len2 + 2)))
		return (NULL);
	i = -1;
	while (++i < len1)
		ret[i] = s1[i];
	ret[i] = '\n';
	i = -1;
	while (++i < len2)
		ret[len1 + i + 1] = s2[i];
	ret[len1 + i + 1] = 0;
	return (ret);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		len1;

	len1 = ft_strlen(s1);
	if (len1 == 0)
	{
		free(s1);
		return (s2);
	}
	ret = join_str(s1, s2, len1);
	free(s1);
	free(s2);
	return (ret);
}
