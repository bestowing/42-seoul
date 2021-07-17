CC=gcc
CFLAGS=-Wall -Wextra -Werror
CBUFFER=-D BUFFER_SIZE=32
SRC=get_next_line.c get_next_line_utils.c
OBJ=$(SRC:.c=.o)
NAME=get_next_line.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -cr $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) $(CBUFFER) -I includes -c $<

clean:
	rm $(NAME) $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all
