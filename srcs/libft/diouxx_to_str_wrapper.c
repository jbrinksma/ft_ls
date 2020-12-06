/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   diouxx_to_str_wrapper.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/09 05:24:57 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:45:57 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	Collection of all the conversions that can be done on 'd', 'i', 'o', 'u',
**	'x' and 'X' types. Will execute and save the conversion in a string which
**	is then passed back to the main conversion wrapper.
*/

static char	*diouxx_to_str_wrapper5(t_va_list *probe)
{
	char *data_str;

	if (probe->data_type == 'X')
	{
		if (probe->length_mod == -1)
			data_str = convert_hex_to_str((unsigned int)probe->data_ptr, 'X');
		if (probe->length_mod == 0)
			data_str = convert_hex_to_str((unsigned char)probe->data_ptr, 'X');
		if (probe->length_mod == 1)
			data_str = convert_hex_to_str((unsigned short)probe->data_ptr, 'X');
		if (probe->length_mod == 2)
			data_str = convert_hex_to_str((unsigned long)probe->data_ptr, 'X');
		if (probe->length_mod == 3)
			data_str = convert_hex_to_str(probe->data_ptr, 'X');
	}
	else
		exit(EXIT_FAILURE);
	if (data_str[0] == '-')
		probe->is_positive = 0;
	else
		probe->is_positive = 1;
	data_str = remove_minus(probe, data_str);
	return (data_str);
}

static char	*diouxx_to_str_wrapper4(t_va_list *probe)
{
	char *data_str;

	if (probe->data_type == 'x')
	{
		if (probe->length_mod == -1)
			data_str = convert_hex_to_str((unsigned int)probe->data_ptr, 'x');
		if (probe->length_mod == 0)
			data_str = convert_hex_to_str((unsigned char)probe->data_ptr, 'x');
		if (probe->length_mod == 1)
			data_str = convert_hex_to_str((unsigned short)probe->data_ptr, 'x');
		if (probe->length_mod == 2)
			data_str = convert_hex_to_str((unsigned long)probe->data_ptr, 'x');
		if (probe->length_mod == 3)
			data_str = convert_hex_to_str(probe->data_ptr, 'x');
	}
	else
		return (diouxx_to_str_wrapper5(probe));
	if (data_str[0] == '-')
		probe->is_positive = 0;
	else
		probe->is_positive = 1;
	data_str = remove_minus(probe, data_str);
	return (data_str);
}

static char	*diouxx_to_str_wrapper3(t_va_list *probe)
{
	char *data_str;

	if (probe->data_type == 'u')
	{
		if (probe->length_mod == -1)
			data_str = ft_uitoa((unsigned int)probe->data_ptr);
		if (probe->length_mod == 0)
			data_str = ft_uitoa((unsigned char)probe->data_ptr);
		if (probe->length_mod == 1)
			data_str = ft_uitoa((unsigned short)probe->data_ptr);
		if (probe->length_mod == 2)
			data_str = ft_ulltoa((unsigned long)probe->data_ptr);
		if (probe->length_mod == 3)
			data_str = ft_ulltoa(probe->data_ptr);
	}
	else
		return (diouxx_to_str_wrapper4(probe));
	if (data_str[0] == '-')
		probe->is_positive = 0;
	else
		probe->is_positive = 1;
	data_str = remove_minus(probe, data_str);
	return (data_str);
}

static char	*diouxx_to_str_wrapper2(t_va_list *probe)
{
	char *data_str;

	if (probe->data_type == 'o')
	{
		if (probe->length_mod == -1)
			data_str = convert_o_to_str((unsigned int)probe->data_ptr);
		if (probe->length_mod == 0)
			data_str = convert_o_to_str((unsigned char)probe->data_ptr);
		if (probe->length_mod == 1)
			data_str = convert_o_to_str((unsigned short)probe->data_ptr);
		if (probe->length_mod == 2)
			data_str = convert_o_to_str((unsigned long)probe->data_ptr);
		if (probe->length_mod == 3)
			data_str = convert_o_to_str(probe->data_ptr);
	}
	else
		return (diouxx_to_str_wrapper3(probe));
	if (data_str[0] == '-')
		probe->is_positive = 0;
	else
		probe->is_positive = 1;
	data_str = remove_minus(probe, data_str);
	return (data_str);
}

char		*diouxx_to_str_wrapper(t_va_list *probe)
{
	char *data_str;

	if (probe->data_type == 'd' || probe->data_type == 'i')
	{
		if (probe->length_mod == -1)
			data_str = ft_itoa((int)probe->data_ptr);
		if (probe->length_mod == 0)
			data_str = ft_itoa((char)probe->data_ptr);
		if (probe->length_mod == 1)
			data_str = ft_itoa((short)probe->data_ptr);
		if (probe->length_mod == 2)
			data_str = ft_lltoa((long)probe->data_ptr);
		if (probe->length_mod == 3)
			data_str = ft_lltoa((long long)probe->data_ptr);
	}
	else
		return (diouxx_to_str_wrapper2(probe));
	if (data_str[0] == '-')
		probe->is_positive = 0;
	else
		probe->is_positive = 1;
	data_str = remove_minus(probe, data_str);
	return (data_str);
}
