CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
NAME	=	libft.a
SRCS	=	ft_strlen.c \
			ft_atoi.c \
			ft_isdigit.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_isstr.c \
			ft_isnbr.c \
			ft_strjoin.c \
			ft_calloc.c \
			ft_memset.c
OBJS	=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -cr $(NAME) $(OBJS)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I includes -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re