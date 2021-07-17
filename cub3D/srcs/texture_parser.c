/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:46:07 by chelee            #+#    #+#             */
/*   Updated: 2021/02/20 05:46:42 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_path(t_game *game, char *path, int dir)
{
	int		width;
	int		height;
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	free(path);
	if (img_ptr == NULL)
		return (handle_error("Texture path is invalid"));
	game->tex_walls[dir].img_ptr = img_ptr;
	game->tex_walls[dir].width = width;
	game->tex_walls[dir].height = height;
	game->tex_walls[dir].data =
		(int *)mlx_get_data_addr(game->tex_walls[dir].img_ptr,
		&(game->tex_walls[dir].bpp), &(game->tex_walls[dir].size_l),
		&(game->tex_walls[dir].endian));
	if (game->tex_walls[dir].data == NULL)
		return (handle_error("Texture path is invalid"));
	return (SUCCESS);
}

int			handle_texture(t_game *game, char *line, int dir)
{
	char	*path;
	int		i;
	int		start;
	int		size;

	i = 2;
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
	return (check_path(game, path, dir));
}
