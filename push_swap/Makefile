NAME		=	push_swap
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRC_NAME	=	main.c
SRC_PATH	=	./srcs
SRCS		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ_PATH	=	./objs
OBJS		=	$(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INCLUDES	=	-I./includes

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re