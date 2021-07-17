/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunichar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 23:09:42 by chelee            #+#    #+#             */
/*   Updated: 2020/11/06 16:02:40 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	put_uni2byte(wchar_t c)
{
	unsigned char	buffer[2];

	buffer[0] = (c >> 6) | 192;
	buffer[1] = (c & 63) | 128;
	return (write(1, buffer, 2));
}

static int	put_uni3byte(wchar_t c)
{
	unsigned char	buffer[3];

	buffer[0] = (c >> 12) | 224;
	buffer[1] = ((c >> 6) & 63) | 128;
	buffer[2] = (c & 63) | 128;
	return (write(1, buffer, 3));
}

static int	put_uni4byte(wchar_t c)
{
	unsigned char	buffer[4];

	buffer[0] = (c >> 18) | 240;
	buffer[1] = ((c >> 12) & 63) | 128;
	buffer[2] = ((c >> 6) & 63) | 128;
	buffer[3] = (c & 63) | 128;
	return (write(1, buffer, 4));
}

int			ft_putunichar(wchar_t c)
{
	int	len;

	len = -1;
	if (c < 128)
		len = write(1, &c, 1);
	else if (c < 2048)
		len = put_uni2byte(c);
	else if (c < 65536)
		len = put_uni3byte(c);
	else if (c < 2097152)
		len = put_uni4byte(c);
	return (len);
}
