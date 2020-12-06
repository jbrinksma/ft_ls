/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc_checker.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/14 21:21:41 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:13:34 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_malloc_checker(void *ptr)
{
	if (!ptr)
		exit(EXIT_FAILURE);
}
