/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_field_width_and_flags.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/09 02:43:49 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:47:56 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*create_padding(int size, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	ft_malloc_checker(str);
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	change_chars_left(t_va_list *probe, int chars_left)
{
	if (probe->flag_plus || !probe->is_positive || probe->flag_space)
		chars_left--;
	if ((probe->data_type == 'x' || probe->data_type == 'X') && \
	probe->data_ptr && probe->flag_hash)
		chars_left -= 2;
	else if (probe->data_type == 'o' && probe->data_ptr && probe->flag_hash)
		chars_left--;
	return (chars_left);
}

int			add_flags(t_va_list *probe, char **str)
{
	char	*temp;

	if (!probe->is_positive)
		temp = ft_strjoin("-", *str);
	else if (probe->flag_plus)
		temp = ft_strjoin("+", *str);
	else if (probe->flag_space)
		temp = ft_strjoin(" ", *str);
	else if (probe->flag_hash && probe->data_ptr && \
	((probe->data_type == 'o' && *str[0] != '0') || \
	probe->data_type == 'x' || probe->data_type == 'X'))
		temp = add_hash_flag(probe, str);
	else
		return (1);
	free(*str);
	*str = temp;
	return (0);
}

void		add_field_width_and_flags(t_va_list *probe, char **data_str,
int chars_left)
{
	char	*result;
	char	*padding;

	if (probe->flag_zero)
	{
		padding = create_padding(chars_left, '0');
		result = ft_strjoin(padding, *data_str);
		add_flags(probe, &result);
	}
	else
	{
		add_flags(probe, data_str);
		padding = create_padding(chars_left, ' ');
		if (!probe->flag_minus)
			result = ft_strjoin(padding, *data_str);
		else
			result = ft_strjoin(*data_str, padding);
	}
	free(padding);
	free(*data_str);
	*data_str = ft_strdup(result);
	free(result);
}

/*
**	Checks if there is field width left over to insert padding.
**	If there is: Checks various flags to see how it should be added
**	and then adds it.
*/

void		check_field_width(t_va_list *probe, char **data_str)
{
	int		chars_left;

	chars_left = probe->field_width - ft_strlen(*data_str);
	chars_left = change_chars_left(probe, chars_left);
	if (chars_left > 0)
		add_field_width_and_flags(probe, data_str, chars_left);
	else
		add_flags(probe, data_str);
}
