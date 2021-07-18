/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_library.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 03:40:10 by chelee            #+#    #+#             */
/*   Updated: 2021/06/25 03:40:49 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin_with_char(const char *s1, const char *s2, char c)
{
	char	*result;
	int		s1_len;
	int		s2_len;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	result = malloc(s1_len + s2_len + 2);
	if (!result)
		return (NULL);
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = c;
	i = 0;
	while (i < s2_len)
	{
		result[s1_len + i + 1] = s2[i];
		i++;
	}
	result[s1_len + i + 1] = '\0';
	return (result);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;
	int		i;

	result = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
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

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
