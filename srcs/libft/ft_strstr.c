/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:17:51 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:14:33 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		needle_len;

	needle_len = ft_strlen(needle);
	i = 0;
	if (needle_len == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (!ft_strncmp(&haystack[i], needle, needle_len))
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
