/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   poxf_converters.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 19:58:23 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:50:25 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	Clears the whole-number part of a double, and then multiplies the double
**	by 10 in order to get one whole-number digit which can then be cast into an
**	unsigned long long which can then be converted and added to a string.
*/

static void		double_precision_algorithm(long double data_double, \
char **str, int precision)
{
	char				*temp;
	char				*lltoa_holder;
	unsigned long long	after_dot;
	long double			next;

	while (precision > 0)
	{
		data_double -= (long long)(data_double / 1) * 1;
		data_double = multiply_double(data_double, 1);
		next = data_double - (long long)(data_double / 1) * 1;
		next = multiply_double(next, 1);
		if ((int)next >= 5)
			data_double += 1;
		temp = ft_strdup(*str);
		free(*str);
		after_dot = (unsigned long long)data_double;
		lltoa_holder = ft_ulltoa(after_dot);
		*str = ft_strjoin_free(temp, lltoa_holder);
		precision--;
	}
}

/*
**	Casts whole-number part of double into long long, which is then
**	handled accordingly.
*/

char			*convert_f_to_str(int flag_hash, long double data_double, \
int precision)
{
	long long			before_dot;
	char				*str;
	char				*temp;

	before_dot = (long long)data_double;
	temp = ft_lltoa(before_dot);
	ft_malloc_checker(temp);
	if (precision != 0 || flag_hash)
		str = ft_strjoin(temp, ".");
	else
		str = ft_strdup(temp);
	free(temp);
	if (data_double < 0)
		data_double *= -1;
	double_precision_algorithm(data_double, &str, precision);
	return (str);
}

char			*convert_o_to_str(unsigned long long data_ptr)
{
	char	*hex_chars;
	char	*rev;
	int		i;

	i = 0;
	hex_chars = ft_strdup("0123456789abcdef");
	rev = (char*)malloc(sizeof(char) * 44);
	ft_malloc_checker(rev);
	if (data_ptr == 0)
	{
		rev[i] = '0';
		i++;
	}
	while (data_ptr > 0)
	{
		rev[i] = hex_chars[data_ptr % 8];
		data_ptr /= 8;
		i++;
	}
	rev[i] = '\0';
	free(hex_chars);
	return (ft_revstr(rev));
}

/*
**	Below functions call get-hex-chars to supply the right chars.
**	'0123456789ABCDEF' or '0123456789abcdef'.
*/

char			*convert_p_to_str(unsigned long long data_ptr)
{
	char	*hex_chars;
	char	*rev;
	int		i;

	i = 0;
	hex_chars = get_hex_chars('p');
	rev = (char*)malloc(sizeof(char) * 33);
	ft_malloc_checker(rev);
	if (data_ptr == 0)
	{
		rev[i] = '0';
		i++;
	}
	while (data_ptr > 0)
	{
		rev[i] = hex_chars[data_ptr % 16];
		data_ptr /= 16;
		i++;
	}
	rev[i] = 'x';
	rev[i + 1] = '0';
	rev[i + 2] = '\0';
	free(hex_chars);
	return (ft_revstr(rev));
}

char			*convert_hex_to_str(unsigned long long data_ptr, char c)
{
	char	*hex_chars;
	char	*rev;
	int		i;

	i = 0;
	hex_chars = get_hex_chars(c);
	rev = (char*)malloc(sizeof(char) * 33);
	ft_malloc_checker(rev);
	if (data_ptr == 0)
	{
		rev[i] = '0';
		i++;
	}
	while (data_ptr > 0)
	{
		rev[i] = hex_chars[data_ptr % 16];
		data_ptr /= 16;
		i++;
	}
	rev[i] = '\0';
	free(hex_chars);
	return (ft_revstr(rev));
}
