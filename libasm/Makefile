NAME		=	libasm.a

SRC_NAME	=	ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s
SRC_PATH	=	./srcs
SRCS		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ_NAME	=	$(SRC_NAME:.s=.o)
OBJ_PATH	=	./objs
OBJS		=	$(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

TESTER_SRC	=	main.c
TESTER_OBJ	=	$(TESTER_SRC:.c=.o)
TESTER		=	libasm_tester

all : $(NAME)

$(NAME) : $(OBJS)
	ar -cr $(NAME) $(OBJS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.s
	nasm -f macho64 $< -o $@

clean :
	rm -f $(OBJS)
	rm -f $(TESTER_OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f $(TESTER)

test : $(TESTER)

$(TESTER) : $(NAME) $(TESTER_OBJ)
	gcc -Wall -Werror -Wextra -I./include/ $(NAME) $(TESTER_OBJ) -o $(TESTER)

$(TESTER_OBJ): $(TESTER_SRC)
	gcc -Wall -Werror -Wextra -I./include/ -o $(TESTER_OBJ) -c $(TESTER_SRC)

re : fclean all

.PHONY : all clean fclean re test