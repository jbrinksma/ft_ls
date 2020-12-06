/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 14:24:44 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 14:58:35 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		u;

	i = 0;
	while ((s1[i] == s2[i] && s1[i] != '\0') && i < n)
		i++;
	if (s1[i] != s2[i] && i < n)
	{
		u = ((unsigned char*)s1)[i] - ((unsigned char*)s2)[i];
		return (u);
	}
	return (0);
}
