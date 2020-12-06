/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extra_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/13 14:52:20 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/14 18:20:01 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*get_hex_chars(char c)
{
	char *chars;

	if (c == 'p' || c == 'x')
		chars = ft_strdup("0123456789abcdef");
	else if (c == 'X')
		chars = ft_strdup("0123456789ABCDEF");
	else
		chars = NULL;
	return (chars);
}

long double	multiply_double(long double data_double, int precision)
{
	if (precision == -1)
		precision = 6;
	while (precision > 0)
	{
		data_double *= 10;
		precision--;
	}
	return (data_double);
}

int			find_null_char(char *data_str, int loc_in_string)
{
	int i;

	i = 0;
	while (data_str[i] != '\0')
	{
		if (data_str[i] == '@')
			return (loc_in_string);
		i++;
		loc_in_string++;
	}
	exit(EXIT_FAILURE);
}

int			find_end_of_str(char *data_str, int loc_in_string)
{
	int i;

	i = 0;
	while (data_str[i] != '\0')
	{
		i++;
		loc_in_string++;
	}
	return (loc_in_string);
}

/*
**	Makes it easy to handle certain flags like '+'.
*/

char		*remove_minus(t_va_list *probe, char *str)
{
	char	*result;

	if (str[0] == '-')
	{
		result = ft_strdup(&str[1]);
		probe->removed_minus = 1;
		free(str);
		return (result);
	}
	return (str);
}
