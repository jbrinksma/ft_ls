/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_precision.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/11 10:45:54 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:47:56 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_precision(t_va_list *probe, char **data_str)
{
	int		len;
	int		total_extra_digits;
	char	*extra_digits;
	char	*temp;
	int		index;

	index = 0;
	len = ft_strlen(*data_str);
	total_extra_digits = probe->precision - len;
	if (total_extra_digits > 0 && probe->data_type != 'f' && probe->data_type \
	!= '%' && probe->data_type != 's')
	{
		extra_digits = (char*)malloc(sizeof(char) * (total_extra_digits + 1));
		ft_malloc_checker(extra_digits);
		while (index < total_extra_digits)
		{
			extra_digits[index] = '0';
			index++;
		}
		extra_digits[index] = '\0';
		temp = ft_strjoin(extra_digits, *data_str);
		free(*data_str);
		free(extra_digits);
		*data_str = temp;
	}
}
