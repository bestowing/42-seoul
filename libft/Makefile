CC=gcc
CFLAGS=-Wall -Werror -Wextra
NAME=libft.a
SOURCES=memset.c bzero.c memcpy.c memccpy.c memmove.c memchr.c memcmp.c strlen.c strlcpy.c strlcat.c strchr.c strrchr.c strnstr.c strncmp.c atoi.c isalpha.c isdigit.c isalnum.c isascii.c isprint.c toupper.c tolower.c calloc.c strdup.c substr.c strjoin.c strtrim.c split.c itoa.c strmapi.c putchar_fd.c putstr_fd.c putendl_fd.c putnbr_fd.c
SOURCES_BONUS=lstnew.c lstadd_front.c lstsize.c lstlast.c lstadd_back.c lstdelone.c lstclear.c lstiter.c lstmap.c
SRCS=$(addprefix ft_, $(SOURCES))
SRCS_BONUS=$(addprefix ft_, $(SOURCES_BONUS))
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -cr $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	ar -cr $(NAME) $(OBJS_BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -I includes -c $<

clean:
	rm $(NAME) $(OBJS) $(OBJS_BONUS)

fclean:
	rm -f $(NAME) $(OBJS) $(OBJS_BONUS)

re: fclean all
