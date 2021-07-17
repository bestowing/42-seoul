NAME		=	cub3D
CC			=	gcc
CFLAGS		=	-O3 -Wall -Wextra -Werror

LIB			=	-L./lib/mlx -lmlx -framework OpenGL -framework AppKit
LIB_2		=	-L./lib/libft -lft
MLX			=	./lib/mlx/libmlx.a
LIBFT		=	./lib/libft/libft.a

RESOL_W		:=	-D MAX_W=$(shell osascript -e 'tell application "Finder" to get bounds of window of desktop' | cut -f 3 -d ',' | cut -c 2-)
RESOL_H		:=	-D MAX_H=$(shell osascript -e 'tell application "Finder" to get bounds of window of desktop' | cut -f 4 -d ',' | cut -c 2-)

SRC_NAME	=	main.c \
				initializer.c \
				textures_initializer.c \
				setter.c \
				textures_setter.c \
				parser.c \
				parser_cont.c \
				resolution_parser.c \
				texture_parser.c \
				item_parser.c \
				color_parser.c \
				get_next_line.c \
				validator.c \
				validator_cont.c \
				map_handler.c \
				player_handler.c \
				player_handler_cont.c \
				enemy_handler.c \
				sprite_handler.c \
				bmp_saver.c \
				render.c \
				render_cont.c \
				render_cont2.c \
				floor_ceiling_renderer.c \
				sprite_renderer.c \
				sprite_renderer_cont.c \
				sprite_renderer_cont2.c \
				sprite_render_helper.c \
				sprite_render_helper2.c \
				hand_renderer.c \
				interface_renderer.c \
				effect_renderer.c \
				hooker.c \
				error_handler.c \
				game_terminator.c
SRC_PATH 	=	./srcs
SRC			=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ_PATH	=	./obj
OBJ			=	$(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC_LINK	=	-I./includes

all		:	$(NAME)

bonus	:	all

$(NAME)	:	 $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INC_LINK) $(LIB_2) $(LIB) -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	gcc $(CFLAGS) $(INC_LINK) $(RESOL_W) $(RESOL_H) -o $@ -c $<

$(MLX) :
	@$(MAKE) -C ./lib/mlx all

$(LIBFT) :
	@$(MAKE) -C ./lib/libft all

clean :
	$(MAKE) -C ./lib/mlx clean
	$(MAKE) -C ./lib/libft clean
	rm -f $(OBJ)

fclean : clean
	$(MAKE) -C ./lib/mlx clean
	$(MAKE) -C ./lib/libft fclean
	rm -f $(NAME) $(MLX) $(LIBFT)

re : fclean all

.PHONY : all clean fclean re bonus