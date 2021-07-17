/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:44:17 by chelee            #+#    #+#             */
/*   Updated: 2021/02/26 16:15:26 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"

/*
** flag indicating the result
*/
# define SUCCESS		0
# define ERROR			-1
# define TRUE			1
# define FALSE			0

/*
** keycode for hooking
*/
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_M			46
# define KEY_J			38
# define KEY_T			17
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_SPACE		49
# define KEY_1			18
# define KEY_2			19

/*
** get_next_line buffer
*/
# define BUFFER_SIZE 	256

/*
** about player
*/
# define JUMP_TIME		18
# define MAX_LIFE		5

/*
** about enemy
*/
# define E_M_SPEED		0.01

/*
** about item
*/
# define I_M_SPEED		0.5

/*
** textures number
*/
# define EAST			0
# define WEST			1
# define SOUTH			2
# define NORTH			3

/*
** for rendering
*/
# define UDIV			3
# define VDIV			3

# define SPRITE_SCR_X	0
# define SPRITE_HEIGHT	1
# define V_MOVE_SCREEN	2
# define DRAW_START_Y	3
# define DRAW_END_Y		4
# define SPRITE_WIDTH	5
# define DRAW_START_X	6
# define DRAW_END_X		7

/*
** about bmp header
*/
# define PIXEL_SIZE		4
# define PIXEL_ALIGN	4

# pragma pack(push, 1)

typedef struct		s_header
{
	unsigned short	file_type;
	unsigned int	file_size;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int	pixel_data_offset;
	unsigned int	header_size;
	int				image_width;
	int				image_height;
	unsigned short	planes;
	unsigned short	bpp;
	unsigned int	compression;
	unsigned int	image_size;
	int				x_pixels_per_meter;
	int				y_pixels_per_meter;
	unsigned int	total_colors;
	unsigned int	important_colors;
}					t_header;

# pragma pack(pop)

typedef struct		s_render
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
}					t_render;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				bpp;
	int				size_l;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct		s_player
{
	int				life;
	int				turn_dir;
	int				walk_dir;
	int				move_dir;
	int				ver_dir;
	int				jump_time;
	int				hit_time;
	int				attack_time;
	int				minimap;
	int				curr_weapon;
	int				has_weapon;
	double			pos_x;
	double			pos_y;
	double			pos_z;
	double			dir_x;
	double			dir_y;
	double			move_x;
	double			move_y;
	double			plane_x;
	double			plane_y;
	double			pitch;
	double			move_speed;
	double			rot_speed;
}					t_player;

typedef struct		s_item
{
	int				move_dir;
	int				hit_time;
	int				life;
	double			pos_x;
	double			pos_y;
	double			pos_z;
	double			move_speed;
}					t_item;

typedef struct		s_enemy
{
	t_img			img;
	int				move_dir;
	int				hit_time;
	int				life;
	double			pos_x;
	double			pos_y;
	double			pos_z;
	double			move_speed;
}					t_enemy;

typedef struct		s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				**map;
	int				*sprite_order;
	int				*sprite_dis;
	int				m_width;
	int				m_height;
	int				s_width;
	int				s_height;
	int				floor_color;
	int				ceiling_color;
	int				item_size;
	int				is_texture;
	t_img			tex_walls[4];
	t_img			tex_weapon[3];
	t_img			tex_hand[2];
	t_img			ceiling;
	t_img			floor;
	t_img			life[2];
	t_img			img;
	t_player		player;
	double			*z_buffer;
	t_enemy			enemy;
	t_item			*items;
	t_item			weapon;
	t_img			item;
	t_img			sword;
}					t_game;

typedef struct		s_content
{
	char			*buff;
	int				index;
	int				len;
}					t_content;

/*
** initializer.c
*/
int					init_game(t_game *game);

/*
** textures_initializer.c
*/
void				init_textures(t_game *game);

/*
** setter.c
*/
int					set_game(t_game *game);

/*
** textures_setter.c
*/
int					set_textures(t_game *game);

/*
** map_handler.c
*/
int					**allo_map(int h, int w);
void				free_map(int **map, int height);

/*
** player_handler.c
*/
void				act_player(t_game *game);
void				set_player(t_game *game, t_player player);
void				player_attack(t_game *game);
void				player_move(t_game *g);

/*
** enemy_handler.c
*/
void				act_enemy(t_game *game);

/*
** sprite_handler.c
*/
void				animate_weapon(t_game *game);
void				animate_item(t_game *game);

/*
** parser.c
*/
int					handle_file(t_game *game, char *name);
int					parse_map(t_game *game, int fd);

/*
** resolution_parser.c
*/
int					handle_resolution(t_game *game, char *line);

/*
** texture_parser.c
*/
int					handle_texture(t_game *game, char *line, int dir);

/*
** item_parser.c
*/
int					handle_item(t_game *game, char *line);

/*
** color_parser.c
*/
int					handle_color(t_game *game, char *line, int is_floor);

/*
** validator.c
*/
int					check_validation(t_game *game, int pos_x, int pos_y);
int					init_visit(int h, int w);
int					***get_visit();
void				destroy_visit(int h);

/*
** bmp_saver.c
*/
int					check_parameter(t_game *game, int argc, char *argv[]);

/*
** floor_seiling_renderer.c
*/
void				render_floor_seiling(t_game *game, int is_texture);

/*
** render.c
*/
void				render(t_game *game);
void				dda(t_render *render, t_game *game, int x);
void				dda_cont(t_render *render, t_game *game, int side, int x);

/*
** sprite_renderer.c
*/
void				render_sprite(t_game *game);

/*
** sprite_renderer_cont.c
*/
double				get_transforms(t_player p,
						double px, double py, double *t_y);
void				render_weapon(t_game *game);
void				render_enemy(t_game *game);
void				render_item(t_game *game, int i);

/*
** sprite_renderer_helper.c
*/
void				sort_items(int order[], int dis[], int l, int r);
void				set_info_z(t_game *game,
						double tr_x, double tr_y, double pos_z);
void				set_render_info(t_game *game, double tr_x, double tr_y);
int					*get_render_info(void);

/*
** hand_renderer.c
*/
void				render_hand(t_game *game);

/*
** interface_renderer.c
*/
void				render_life(t_game *game);
void				render_map(t_game *game, int px, int py, int tile);

/*
** effect_renderer.c
*/
void				render_hit(t_game *game);
int					effect_hit_color(int old);

/*
** hooker.c
*/
int					move_mouse(int x, int y, t_game *game);
int					press_key(int keycode, t_game *game);
int					release_key(int keycode, t_player *player);

/*
** get_next_line.c
*/
int					get_next_line(int fd, char **line);

/*
** error_handler.c
*/
int					handle_error(char *message);
int					handle_strerror();

/*
** game_terminator.c
*/
int					exit_game(t_game *game);

#endif
