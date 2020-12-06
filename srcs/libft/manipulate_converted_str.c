/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manipulate_converted_str.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/09 02:37:22 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:46:01 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	Filters invalid flag combinations and edge cases of specific flag
**	or other conversion specific combinations. Amd adds precision and
**	field width.
*/

void	manipulate_converted_str(t_va_list *probe, char **data_str, \
int loc_in_string)
{
	if ((probe->flag_zero && probe->flag_minus) || (probe->precision >= 0 \
	&& probe->data_type != 'f' && probe->data_type != 'c' \
	&& probe->data_type != 's' && probe->data_type != 'p'))
		probe->flag_zero = 0;
	if ((probe->flag_space && probe->flag_plus) || !probe->is_positive \
	|| probe->data_type == 'u' || probe->data_type == 'x' \
	|| probe->data_type == 'X' || probe->data_type == 'c' \
	|| probe->data_type == 's' || probe->data_type == 'p' \
	|| probe->data_type == '%')
		probe->flag_space = 0;
	if (probe->flag_plus && probe->data_type != 'd' && probe->data_type != 'i' \
	&& probe->data_type != 'f')
		probe->flag_plus = 0;
	add_precision(probe, data_str);
	check_field_width(probe, data_str);
	if (probe->data_type == 'c' && (char)probe->data_ptr == 0)
		probe->empty_char_index = find_null_char(*data_str, loc_in_string);
}

char	*add_hash_flag(t_va_list *probe, char **data_str)
{
	char	*result;

	if (probe->data_type == 'o' && *data_str[0] != '0' && probe->data_ptr)
		result = ft_strjoin("0", *data_str);
	else if (probe->data_type == 'x' && probe->data_ptr)
		result = ft_strjoin("0x", *data_str);
	else if (probe->data_type == 'X' && probe->data_ptr)
		result = ft_strjoin("0X", *data_str);
	else
		exit(EXIT_FAILURE);
	return (result);
}

void	add_space_flag(t_va_list *probe, char **data_str)
{
	char	*result;

	if (probe->flag_space && !probe->flag_zero && probe->is_positive)
	{
		if (*data_str[0] != ' ')
		{
			result = ft_strjoin(" ", *data_str);
			free(*data_str);
			*data_str = result;
		}
	}
}

void	add_plus_flag(t_va_list *probe, char **data_str)
{
	char	*result;

	if (probe->flag_plus && *data_str[0] != '-')
	{
		result = ft_strjoin("+", *data_str);
		free(*data_str);
		*data_str = result;
	}
}
