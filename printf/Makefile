NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRC=ft_printf.c \
	ft_printf_print_manager.c \
	ft_printf_data_parser.c \
	ft_printf_parsing_helper.c \
	ft_printf_data_printer.c \
	ft_printf_c_type.c \
	ft_printf_s_type.c \
	ft_printf_p_type.c \
	ft_printf_d_type.c \
	ft_printf_u_type.c \
	ft_printf_x_type.c \
	ft_printf_o_type.c \
	ft_printf_percent_type.c \
	ft_printf_n_type.c \
	ft_printf_f_type.c \
	ft_printf_f_type_cont.c \
	ft_printf_e_type.c \
	ft_printf_e_type_cont.c \
	ft_printf_g_type.c \
	ft_printf_g_type_cont.c \
	ft_printf_g_type_cont2.c \
	ft_printf_print_utils.c \
	ft_printf_int_utils.c \
	ft_printf_float_utils.c \
	ft_printf_float_utils_cont.c \
	ft_printf_float_utils_cont2.c
OBJS=$(SRC:.c=.o)
LIB_A=libft.a

all : $(NAME)

bonus : all

$(NAME) : $(OBJS) $(LIB_A)
	cp $(LIB_A) $(NAME)
	ar -cr $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I includes -c $<

$(LIB_A) :
	$(MAKE) -C ./libft all
	cp ./libft/$(LIB_A) .

clean :
	$(MAKE) -C ./libft clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME) $(LIB_A)

re : fclean all

.PHONY : all clean fclean re bonus