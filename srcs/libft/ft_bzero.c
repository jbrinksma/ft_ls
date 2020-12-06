/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <intranet_username@stude...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 15:37:28 by jbrinksm      #+#    #+#                 */
/*   Updated: 2019/01/10 17:32:05 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n == 0)
		return ;
	else
		ft_memset(s, 0, n);
}
