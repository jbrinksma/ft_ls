/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 21:53:01 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/04 14:17:14 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	const_start;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	const_start = start;
	new_str = (char*)malloc((len + 1) * sizeof(char));
	if (new_str == 0)
		exit(EXIT_FAILURE);
	while (start < const_start + len)
	{
		new_str[i] = s[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}
