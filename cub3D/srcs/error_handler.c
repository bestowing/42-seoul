/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:46:00 by chelee            #+#    #+#             */
/*   Updated: 2021/02/19 10:55:14 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		handle_error(char *message)
{
	printf("Error\n%s", message);
	return (ERROR);
}

int		handle_strerror(void)
{
	printf("Error\n%s", strerror(errno));
	return (ERROR);
}
