/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   replace_conversion_specification.c                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 16:23:46 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/14 17:57:21 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	find_start(char **format_cpy, size_t index)
{
	while ((*format_cpy)[index] != '%' && (*format_cpy)[index] != '\0')
		index++;
	if ((*format_cpy)[index] == '%')
		return (index);
	exit(EXIT_FAILURE);
}

/*
**	/\                                                         /\
**	These two return the start and end of a conversion specifier.
**	\/                                                         \/
*/

static int	find_end(char **format_cpy, size_t index)
{
	index++;
	while ((*format_cpy)[index] != '%' && \
	(*format_cpy)[index] != 'f' && (*format_cpy)[index] != 'X' && \
	(*format_cpy)[index] != 'x' && (*format_cpy)[index] != 'u' && \
	(*format_cpy)[index] != 'o' && (*format_cpy)[index] != 'p' && \
	(*format_cpy)[index] != 'i' && (*format_cpy)[index] != 'd' && \
	(*format_cpy)[index] != 'c' && (*format_cpy)[index] != 's' && \
	(*format_cpy)[index] != '\0')
		index++;
	if ((*format_cpy)[index] == '%' || \
	(*format_cpy)[index] == 'f' || (*format_cpy)[index] == 'X' || \
	(*format_cpy)[index] == 'x' || (*format_cpy)[index] == 'u' || \
	(*format_cpy)[index] == 'o' || (*format_cpy)[index] == 'p' || \
	(*format_cpy)[index] == 'i' || (*format_cpy)[index] == 'd' || \
	(*format_cpy)[index] == 'c' || (*format_cpy)[index] == 's')
		return (index);
	exit(EXIT_FAILURE);
}

/*
**	This is where the conversion specification part of the string
**	(which is delimited by "start" and "end" variables) is
**	replaced with the correct conversion.
*/

static void	replacer(char **format_cpy, size_t start, size_t end, \
t_va_list *probe)
{
	char	*front;
	char	*behind;
	char	*between;

	front = ft_strndup(*format_cpy, start);
	between = conversions_to_str_wrapper(probe, ft_strlen(front));
	behind = ft_strdup(*format_cpy + end + 1);
	free(*format_cpy);
	*format_cpy = ft_strjoin_free(front, between);
	front = ft_strjoin_free(*format_cpy, behind);
	*format_cpy = ft_strdup(front);
	free(front);
}

/*
**	All data except for double values can be stored in unsigned long long.
**	Therefore I will check the conversion specifier here and store
**	the data accordingly.
*/

void		replace_conversion_specification(t_va_list *data_lst, \
char **format_cpy, va_list va, int *i)
{
	size_t		conv_spec_start;
	size_t		conv_spec_end;
	t_va_list	*probe;

	probe = data_lst;
	while (probe->next != NULL)
		probe = probe->next;
	if (probe->data_type == 'f')
	{
		if (probe->length_mod != 4)
			probe->data_double = va_arg(va, double);
		else
			probe->data_double = va_arg(va, long double);
	}
	else if (probe->data_type != '%')
		probe->data_ptr = va_arg(va, unsigned long long);
	conv_spec_start = find_start(format_cpy, *i);
	conv_spec_end = find_end(format_cpy, conv_spec_start);
	replacer(format_cpy, conv_spec_start, conv_spec_end, probe);
}
