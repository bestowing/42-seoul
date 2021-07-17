/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_saver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:39:04 by chelee            #+#    #+#             */
/*   Updated: 2021/02/19 10:43:17 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_header	get_header(t_game game)
{
	t_header	header;

	header.file_type = 19778;
	header.file_size = 54 + PIXEL_SIZE * game.s_height * game.s_width;
	header.reserved1 = 0;
	header.reserved2 = 0;
	header.pixel_data_offset = 54;
	header.header_size = 40;
	header.image_width = game.s_width;
	header.image_height = game.s_height;
	header.planes = 1;
	header.bpp = 32;
	header.compression = 0;
	header.image_size = PIXEL_SIZE * game.s_height * game.s_width;
	header.x_pixels_per_meter = 0;
	header.y_pixels_per_meter = 0;
	header.total_colors = 0xffffff;
	header.important_colors = 0;
	return (header);
}

static int		get_padding(t_game game)
{
	int	w;
	int ret;

	w = game.s_width;
	ret = (w * PIXEL_SIZE) % PIXEL_ALIGN;
	ret = (4 - ret) % PIXEL_ALIGN;
	return (ret);
}

static void		rgba_handler(t_game game, int fd, int padding)
{
	int	w;
	int	h;

	h = game.s_height;
	while (--h >= 0)
	{
		w = -1;
		while (++w < game.s_width)
			write(fd, &game.img.data[h * game.s_width + w], 4);
		w = -1;
		while (++w < padding)
			write(fd, "0", 4);
	}
	return ;
}

static int		handle_bitmap(t_game game)
{
	t_header	header;
	int			fd;

	fd = open("cub3D.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd < 0)
		return (handle_strerror());
	header = get_header(game);
	write(fd, &header, 54);
	rgba_handler(game, fd, get_padding(game));
	if (close(fd) == -1)
		return (handle_strerror());
	printf("the first rendered image has saved.");
	return (TRUE);
}

int				check_parameter(t_game *game, int argc, char *argv[])
{
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) != 6 || argv[2][0] != '-' ||
			argv[2][1] != '-' || argv[2][2] != 's' ||
			argv[2][3] != 'a' || argv[2][4] != 'v' ||
			argv[2][5] != 'e')
			return (handle_error("second argument is not \"--save\""));
		if (handle_bitmap(*game) == TRUE)
			exit_game(game);
	}
	return (FALSE);
}
