/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:06:01 by chelee            #+#    #+#             */
/*   Updated: 2021/04/25 19:14:35 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBASM_H
# define _LIBASM_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_RESET	"\x1b[0m"

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

#endif