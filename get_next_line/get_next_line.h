/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@42seoul.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:05:37 by chelee            #+#    #+#             */
/*   Updated: 2020/10/08 03:39:06 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_content
{
	char		*buff;
	size_t		index;
	size_t		len;
}				t_content;

int				get_next_line(int fd, char **line);
int				read_this_line(int fd, char **line);
int				travel_buffer(t_content *content, char **line);
int				update_buffer(int fd, char **buffer, t_content *content);
size_t			my_strlen(char *str);
int				buff_to_line(char **line, char *buffer, size_t idx, size_t len);
int				is_in_newline(char *buffer, size_t start, size_t size);
size_t			my_strchr(char *buffer, size_t start, size_t size);

#endif
