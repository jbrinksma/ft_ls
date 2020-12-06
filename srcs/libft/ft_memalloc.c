/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:47:51 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:48:26 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	mem = (unsigned char*)malloc(size * sizeof(unsigned char));
	ft_malloc_checker(mem);
	ft_memset((void*)mem, 0, size);
	return (mem);
}
