/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 18:19:32 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:51:14 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_va_list
{
	unsigned long long	data_ptr;
	long double			data_double;
	char				data_type;
	int					flag_hash;
	int					flag_zero;
	int					flag_minus;
	int					flag_space;
	int					flag_plus;
	int					field_width;
	int					field_width_var;
	int					precision;
	int					length_mod;
	int					removed_minus;
	int					is_positive;
	int					null_chars;
	int					empty_char_index;
	int					is_empty;
	int					end_of_str;
	struct s_va_list	*next;
}				t_va_list;

int				count_conversion_specifiers(const char *format);
void			replace_empty_chars(t_va_list *data_lst, char *format_cpy);
int				return_unaltered(const char *format, char *format_cpy, \
t_va_list *data_list, int is_error);
int				ft_printf(const char *format, ...);
int				handle_flags(t_va_list *data_list, char **format_cpy,
va_list vl, int percentages);

/*
**	struct_handlers.c
*/

t_va_list		*make_va_item(void);
t_va_list		*add_item_va_list(t_va_list *data_list);
t_va_list		*last_item(t_va_list *data_list);
void			clear_list(t_va_list *data_list);

/*
**	read_conversion_specification.c
*/

int				read_conversion_specification(t_va_list *data_list, \
char **format_cpy, int *i, va_list vl);
void			flag_type_checker(t_va_list *probe, char *format, int *i);
void			field_width_checker(t_va_list *probe, \
char *format, int *i, va_list vl);
void			length_mod_checker(t_va_list *probe, char *format, int *i);
int				conv_type_checker(t_va_list *probe, char *format, int *i);
void			precision_checker(t_va_list *probe, char *format, int *i);

/*
**	replace_conversion_specification.c
*/

void			replace_conversion_specification(t_va_list *data_lst,
char **format_cpy, va_list va, int *i);

/*
**	conversions_to_str_wrapper.c
*/

char			*conversions_to_str_wrapper(t_va_list *probe,
int loc_in_string);
char			*char_wrapper(t_va_list *probe);
char			*str_wrapper(t_va_list *probe);
char			*ptr_wrapper(t_va_list *probe);
char			*double_wrapper(t_va_list *probe);

/*
**	diouxx_to_str_wrapper.c
*/

char			*diouxx_to_str_wrapper(t_va_list *probe);

/*
**	poxf_converters.c
*/

char			*convert_p_to_str(unsigned long long data_ptr);
char			*convert_o_to_str(unsigned long long data_ptr);
char			*convert_hex_to_str(unsigned long long data_ptr, char c);
char			*convert_f_to_str(int hash_flag, long double data_double,
int precision);

/*
**	manipulate_converted_str.c
*/

void			manipulate_converted_str(t_va_list *probe, char **data_str,
int loc_in_string);
char			*add_hash_flag(t_va_list *probe, char **data_str);
void			add_space_flag(t_va_list *probe, char **data_str);
void			add_plus_flag(t_va_list *probe, char **data_str);

/*
**	add_precision.c
*/

void			add_precision(t_va_list *probe, char **data_str);

/*
**	add_field_width_and_flags.c
*/

void			check_field_width(t_va_list *probe, char **data_str);
void			add_field_width_and_flags(t_va_list *probe, char **data_str,
int chars_left);
char			*create_padding(int size, char c);

/*
**	extra_functions.c
*/

char			*get_hex_chars(char c);
long double		multiply_double(long double data_double, int precision);
int				find_null_char(char *data_str, int loc_in_string);
int				find_end_of_str(char *data_str, int loc_in_string);
char			*remove_minus(t_va_list *probe, char *str);

/*
**	ft_error_printf.c
*/

int				ft_error_printf(const char *format, ...);
void			ft_putnerrorstr(char *str, int n);
void			ft_puterrorchar(char c);

#endif
