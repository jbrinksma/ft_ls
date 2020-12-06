/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversions_to_str_wrapper.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/07 11:02:49 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/14 21:05:25 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	Main wrapper for conversion functions. Looks at data_list probe to see
**	which type of conversion has to be done and then sends it to the right
**	function. Afterwards it also adds any flags which have to be added
**	at the end, along with the optional field width.
*/

char	*conversions_to_str_wrapper(t_va_list *probe, int loc_in_string)
{
	char	*data_str;

	if (probe->data_type == 'c' || probe->data_type == '%')
		data_str = char_wrapper(probe);
	else if (probe->data_type == 's')
		data_str = str_wrapper(probe);
	else if (probe->data_type == 'p')
		data_str = ptr_wrapper(probe);
	else if (\
	probe->data_type == 'd' || probe->data_type == 'i' || \
	probe->data_type == 'o' || probe->data_type == 'u' || \
	probe->data_type == 'x' || probe->data_type == 'X')
		data_str = diouxx_to_str_wrapper(probe);
	else if (probe->data_type == 'f')
		data_str = double_wrapper(probe);
	else if (probe->data_type == '%')
		data_str = ft_char_to_str('%');
	if (!ft_strcmp(data_str, "0") && probe->precision == 0 && \
	probe->data_ptr == 0 && probe->data_type != 'f' \
	&& (probe->data_type != 'o' || !probe->flag_hash))
		data_str[0] = '\0';
	manipulate_converted_str(probe, &data_str, loc_in_string);
	probe->end_of_str = find_end_of_str(data_str, loc_in_string);
	return (data_str);
}

char	*char_wrapper(t_va_list *probe)
{
	if ((char)probe->data_ptr == 0 && probe->data_type != '%')
		return (ft_char_to_str('@'));
	else if (probe->data_type == '%')
		return (ft_char_to_str('%'));
	else
		return (ft_char_to_str((char)probe->data_ptr));
}

char	*str_wrapper(t_va_list *probe)
{
	char	*null_str;
	char	*result;

	if (probe->data_ptr == 0)
	{
		null_str = ft_strdup("(null)");
		result = ft_strndup(null_str, probe->precision);
		free(null_str);
		return (result);
	}
	else if (probe->precision != -1)
		return (ft_strndup((char*)probe->data_ptr, (size_t)probe->precision));
	else
		return (ft_strdup((char*)probe->data_ptr));
}

char	*ptr_wrapper(t_va_list *probe)
{
	return (convert_p_to_str(probe->data_ptr));
}

char	*double_wrapper(t_va_list *probe)
{
	if (probe->data_type == 'f' && probe->precision == -1)
		probe->precision = 6;
	if (probe->length_mod == 4)
		return (convert_f_to_str(probe->flag_hash, probe->data_double, \
		probe->precision));
	else if (probe->length_mod == -1 || probe->length_mod == 2)
		return (convert_f_to_str(probe->flag_hash, (double)probe->data_double, \
		probe->precision));
	else
		exit(EXIT_FAILURE);
}
