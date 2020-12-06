/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unsintlen.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 10:12:43 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 14:58:35 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unsintlen(unsigned int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}
