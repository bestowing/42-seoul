/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:42:30 by chelee            #+#    #+#             */
/*   Updated: 2021/02/19 11:46:40 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <stdlib.h>

int		ft_strlen(char *s);
int		ft_atoi(char *str, int *idx);
int		ft_isdigit(char c);
char	*ft_strtrim(char *s1);
char	*ft_substr(char *s, int start, int len);
int		ft_isstr(char *str);
int		ft_isnbr(char c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(int count, int size);
void	*ft_memset(void *b, int c, int len);

#endif