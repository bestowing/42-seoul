/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:08:31 by chelee            #+#    #+#             */
/*   Updated: 2020/09/30 23:58:25 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cnt_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			words++;
			while (s[i] != c && s[i] != 0)
				i++;
		}
	}
	return (words);
}

static char		*allo_word(char const *s_start, char c)
{
	char	*result;
	size_t	i;

	i = 0;
	while (s_start[i] && s_start[i] != c)
		i++;
	if ((result = (char *)malloc(i + 1)) == 0)
		return (0);
	i = 0;
	while (s_start[i] && s_start[i] != c)
	{
		result[i] = s_start[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

static void		free_word(char **words, size_t cnt)
{
	size_t	i;

	i = 0;
	while (i < cnt)
		free(words[i++]);
	return ;
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;
	if (!s || (result = malloc(sizeof(char *) * (cnt_words(s, c) + 1))) == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			if ((result[cnt++] = allo_word(s + i, c)) == 0)
			{
				free_word(result, cnt - 1);
				return (0);
			}
			while (s[i] && s[i] != c)
				i++;
		}
	}
	result[cnt] = 0;
	return (result);
}
