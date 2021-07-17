/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 03:20:30 by chelee            #+#    #+#             */
/*   Updated: 2021/02/11 15:08:25 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char *s, int start, int len)
{
	char	*ret;
	int		i;

	if ((ret = malloc(len + 1)))
	{
		i = -1;
		while (++i < len)
			ret[i] = s[start + i];
		ret[len] = 0;
	}
	free(s);
	return (ret);
}
