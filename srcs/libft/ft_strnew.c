/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 18:19:35 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/01/14 17:55:38 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char*)malloc((size + 1) * sizeof(char));
	if (!str)
		exit(EXIT_FAILURE);
	ft_memset((void*)str, 0, size + 1);
	return (str);
}
