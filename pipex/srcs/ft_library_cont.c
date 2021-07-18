/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_library_cont.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 03:41:02 by chelee            #+#    #+#             */
/*   Updated: 2021/06/26 14:22:05 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int			ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	cnt_words(const char *s, char c)
{
	int	words;
	int	i;

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

static char	*allo_word(const char *s_start, char c)
{
	char	*result;
	int		i;

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

static void	free_word(char **words, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		free(words[i]);
		words[i] = NULL;
		i++;
	}
	return ;
}

char		**ft_split(const char *s, char c)
{
	char	**result;
	int		cnt;
	int		i;

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
