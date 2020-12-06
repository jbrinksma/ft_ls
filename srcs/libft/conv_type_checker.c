/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_type_checker.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 14:51:57 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/20 15:19:47 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	Returns 1 if dealing with unsupported or invalid
**	conversion specification.
*/

int		conv_type_checker(t_va_list *probe, char *format, int *i)
{
	if (format[*i] == 'c')
		probe->data_type = 'c';
	else if (format[*i] == 's')
		probe->data_type = 's';
	else if (format[*i] == 'p')
		probe->data_type = 'p';
	else if (format[*i] == 'd' || format[*i] == 'i')
		probe->data_type = 'd';
	else if (format[*i] == 'o')
		probe->data_type = 'o';
	else if (format[*i] == 'u')
		probe->data_type = 'u';
	else if (format[*i] == 'x')
		probe->data_type = 'x';
	else if (format[*i] == 'X')
		probe->data_type = 'X';
	else if (format[*i] == 'f')
		probe->data_type = 'f';
	else if (format[*i] == '%')
		probe->data_type = '%';
	else
		return (1);
	(*i)++;
	return (0);
}
