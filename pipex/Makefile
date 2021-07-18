# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chelee <chelee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 12:13:08 by chelee            #+#    #+#              #
#    Updated: 2021/07/17 12:13:09 by chelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

SRC_NAME	=	main.c \
				redirection.c \
				cmd_handler.c \
				parser.c \
				ft_library.c \
				ft_library_cont.c \
				get_next_line.c
SRC_PATH	=	./srcs
SRCS		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ_PATH	=	./objs
OBJS		=	$(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC_LINK	=	-I./includes

all : $(NAME)

bonus : all

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INC_LINK) -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(INC_LINK) -o $@ -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
