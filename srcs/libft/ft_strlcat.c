/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:41:51 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/03 21:52:26 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	end;
	size_t	orig_dst;

	orig_dst = ft_strlen(dst);
	i = 0;
	end = ft_strlen(dst);
	if (end > size)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && i < (int)size - (int)orig_dst - 1)
	{
		dst[end] = src[i];
		end++;
		i++;
		if (src[i] == '\0' || i == (int)size - (int)orig_dst - 1)
		{
			dst[end] = '\0';
			return (orig_dst + ft_strlen(src));
		}
	}
	return (orig_dst + ft_strlen(src));
}
