/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 21:01:22 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/20 12:06:00 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			count_conversion_specifiers(const char *format)
{
	int index;
	int counter;

	index = 0;
	counter = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			while (format[index] != '%' && \
			format[index] != 'f' && format[index] != 'X' && \
			format[index] != 'x' && format[index] != 'u' && \
			format[index] != 'o' && format[index] != 'p' && \
			format[index] != 'i' && format[index] != 'd' && \
			format[index] != 'c' && format[index] != 's' && \
			format[index] != '\0')
				index++;
			counter++;
		}
		index++;
	}
	return (counter);
}

void		replace_empty_chars(t_va_list *data_lst, char *format_cpy)
{
	t_va_list	*probe;
	int			index;

	probe = data_lst;
	while (probe != NULL)
	{
		index = probe->empty_char_index;
		if (index >= 0)
		{
			if (format_cpy[index] == '@')
				format_cpy[index] = '\0';
			else
				exit(EXIT_FAILURE);
		}
		probe = probe->next;
	}
}

/*
**	For every '%' found, apply the proper conversion. This will be done on a
**	%foo by %foo basis e.g. a single call to "replace_conversion_specification"
**	will turn: "xxxxx%dxxxxx%dxxx" into "xxxxxNUMxxxxx%dxxx".
**	This is repeated until there are no more conversion specifiers
*/

int			handle_flags(t_va_list *data_list, char **format_cpy, \
va_list vl, int conversion_specifiers)
{
	int			index;

	index = 0;
	while (conversion_specifiers > 0)
	{
		if (read_conversion_specification(data_list, format_cpy, &index, vl))
			return (1);
		replace_conversion_specification(data_list, format_cpy, vl, &index);
		index = last_item(data_list)->end_of_str;
		conversion_specifiers--;
	}
	va_end(vl);
	return (0);
}

/*
**	I have chosen to return the whole input unaltered whenever the program
**	runs into an error (e.g. syntax error or unsupported flags/conversions).
*/

int			return_unaltered(const char *format, char *format_cpy, \
t_va_list *data_list, int is_error)
{
	ft_putstr(format);
	clear_list(data_list);
	free(format_cpy);
	if (is_error)
		return (-1);
	return (ft_strlen(format));
}

/*
**	One copy of format is used to modify and replace all conversion specifiers.
*/

int			ft_printf(const char *format, ...)
{
	t_va_list	*data_list;
	va_list		vl;
	int			conversion_specifiers;
	char		*format_cpy;
	int			total_bytes;

	format_cpy = ft_strdup(format);
	data_list = make_va_item();
	va_start(vl, format);
	conversion_specifiers = count_conversion_specifiers(format);
	if (conversion_specifiers == 0)
		return (return_unaltered(format, format_cpy, data_list, 0));
	else
	{
		if (handle_flags(data_list, &format_cpy, vl, conversion_specifiers))
			return (return_unaltered(format, format_cpy, data_list, 1));
		total_bytes = ft_strlen(format_cpy);
		replace_empty_chars(data_list, format_cpy);
		ft_putnstr(format_cpy, total_bytes);
		clear_list(data_list);
		free(format_cpy);
		return (total_bytes);
	}
}
