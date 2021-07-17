/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 01:38:08 by chelee            #+#    #+#             */
/*   Updated: 2021/02/20 05:49:08 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_path(t_game *game, char *path)
{
	int		width;
	int		height;
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	free(path);
	if (img_ptr == NULL)
		return (handle_error("sprite texture path is invalid"));
	game->item.img_ptr = img_ptr;
	game->item.width = width;
	game->item.height = height;
	game->item.data = (int *)mlx_get_data_addr(game->item.img_ptr,
		&(game->item.bpp), &(game->item.size_l), &(game->item.endian));
	if (game->item.data == NULL)
		return (handle_error("sprite texture path is invalid"));
	return (SUCCESS);
}

int			handle_item(t_game *game, char *line)
{
	char	*path;
	int		i;
	int		start;
	int		size;

	i = 1;
	while (line[i] && line[i] == ' ')
		i++;
	start = i;
	while (line[i])
		i++;
	size = i - start;
	path = ft_substr(line, start, size);
	if (path == NULL)
		return (handle_error("failed to allocate memory"));
	else if (size < 4 || path[size - 4] != '.' || path[size - 3] != 'x'
		|| path[size - 2] != 'p' || path[size - 1] != 'm')
	{
		free(path);
		return (handle_error("Texture file extension is not '.xpm'"));
	}
	return (check_path(game, path));
}
