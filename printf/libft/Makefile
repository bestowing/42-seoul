CC=gcc
CFLAGS=-Wall -Werror -Wextra
NAME=libft.a
SOURCES=memset.c \
		bzero.c \
		memcpy.c \
		memccpy.c \
		memmove.c \
		memchr.c \
		memcmp.c \
		strlen.c \
		strlcpy.c \
		strlcat.c \
		strchr.c \
		strrchr.c \
		strnstr.c \
		strncmp.c \
		atoi.c \
		isalpha.c \
		isdigit.c \
		isnegative_double.c \
		isalnum.c \
		isascii.c \
		isprint.c \
		toupper.c \
		tolower.c \
		calloc.c \
		strdup.c \
		substr.c \
		strjoin.c \
		strtrim.c \
		split.c \
		itoa.c \
		ftoa.c ftoa_cont.c ftoa_fraction.c ftoa_multi_bigint.c ftoa_multi_bigint_int.c ftoa_add_bigint.c ftoa_add_bigint_int.c ftoa_concat.c \
		strmapi.c \
		putchar_fd.c \
		putunichar.c \
		putstr_fd.c \
		putendl_fd.c \
		putnbr_fd.c
SRCS=$(addprefix ft_, $(SOURCES))
OBJS=$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -cr $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I includes -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
