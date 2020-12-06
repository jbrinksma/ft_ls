/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 13:07:22 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/04 14:10:52 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const	char *needle, size_t len)
{
	size_t	i;
	int		needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0' && i + needle_len <= len)
	{
		if (!ft_strncmp(&haystack[i], needle, needle_len))
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
