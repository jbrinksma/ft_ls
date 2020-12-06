/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wordlength.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 11:23:43 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/04 12:33:47 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordlength(const char *str, char delimiter)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != delimiter)
		i++;
	return (i);
}
