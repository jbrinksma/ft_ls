/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error_printf.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:06:23 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/20 12:10:49 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_error_printf(const char *format, ...)
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
		ft_putnerrorstr(format_cpy, total_bytes);
		clear_list(data_list);
		free(format_cpy);
		return (total_bytes);
	}
}

void		ft_putnerrorstr(char *str, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_puterrorchar(str[i]);
		i++;
	}
}

void		ft_puterrorchar(char c)
{
	write(2, &c, 1);
}
