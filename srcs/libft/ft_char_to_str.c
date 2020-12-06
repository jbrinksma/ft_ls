/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_char_to_str.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/09 05:19:45 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:13:05 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_to_str(char c)
{
	char	*data_str;

	data_str = (char*)malloc(sizeof(char) * 2);
	ft_malloc_checker(data_str);
	data_str[0] = c;
	data_str[1] = '\0';
	return (data_str);
}
