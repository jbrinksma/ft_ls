/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uitoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 09:13:15 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:13:05 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_uitoa(unsigned int n)
{
	char	*strint;
	int		len;

	len = ft_unsintlen(n);
	strint = (char*)malloc(sizeof(char) * (len + 1));
	ft_malloc_checker(strint);
	strint[len] = '\0';
	len--;
	if (n == 0)
		strint[len] = '0';
	while (n > 0)
	{
		strint[len] = n % 10 + '0';
		len--;
		n /= 10;
	}
	return (strint);
}
