/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:33:42 by chelee            #+#    #+#             */
/*   Updated: 2020/11/08 16:03:16 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>

# define ERROR -1
# define SUCCESS 0
# define TRUE 1
# define FALSE 0

typedef struct	s_data
{
	int			flag_minus;
	int			flag_zero;
	int			flag_plus;
	int			flag_blank;
	int			flag_hash;
	int			width;
	int			precision;
	char		length;
	char		type;
	char		sign;
	void		*value;
}				t_data;

/*
** ft_printf.c
*/
int				ft_printf(const char *format, ...);

/*
** ft_printf_print_manager.c
*/
int				manage_print(const char *format, va_list ap);

/*
** ft_printf_data_parser.c
*/
int				parse_data(const char *format, va_list ap, int *idx, int len);

/*
** ft_printf_parsing_helper.c
*/
int				is_flag(char c);
int				is_nbr(char c);
int				is_length(char c);
int				is_type_chr(char c);

/*
** ft_printf_data_printer.c
*/
int				print_data(va_list ap, t_data d, int len);

/*
** ft_printf_*_type.c
*/
int				handle_c_type(va_list ap, t_data d);
int				handle_s_type(va_list ap, t_data d);
int				handle_p_type(va_list ap, t_data d);
int				handle_d_type(va_list ap, t_data d);
int				handle_u_type(va_list ap, t_data d);
int				handle_x_type(va_list ap, t_data d);
int				handle_o_type(va_list ap, t_data d);
int				handle_percent_type(t_data d);
int				handle_n_type(va_list ap, t_data d, int len);
int				handle_f_type(va_list ap, t_data d);
int				print_f(t_data d, char *f);
int				print_special(t_data d, char *f);
int				handle_e_type(va_list ap, t_data d);
int				print_e(t_data d, char *f, int e);
int				handle_g_type(va_list ap, t_data d);
int				select_f_type(t_data d, char *f);
int				select_e_type(t_data d, char *f, int e);

/*
** ft_printf_print_utils.c
*/
void			ft_putullnbr_fd(unsigned long long n, int base, int upper);
void			ft_putllnbr_fd(long long n, int base, int upper);
void			print_offset(int cnt, int flag_zero);

/*
** ft_printf_int_utils.c
*/
int				cnt_nbr_size(long long n, int base, int is_unsigned);
void			get_value(va_list ap, t_data d, long long *v, int is_unsigned);
void			set_sign(t_data *d, long long *value);

/*
** ft_printf_float_utils.c
*/
char			*ft_handle_precision(t_data d, char *f, int *e);
char			*expand_fraction(char *f, int point_idx, int precision);
void			set_double_sign(t_data *d, double v);
int				find_chr(char *f);
int				find_valid_nbr(char *f);
void			manage_fraction(char **f, int flag_hash);
char			*round_fraction(char *f, int point_idx, int precision, int *e);
char			*re_normalize(char *f);
int				ft_add_rounding(char **f, int idx);
int				ft_handle_rounding(char *f, int curr, int next);

/*
** libft
*/
void			ft_putnbr_fd(int n, int fd);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_ftoa(double f);
int				ft_isnegative_double(double d);
char			*ft_strdup(const char *s1);
int				ft_putunichar(wchar_t c);

#endif
