/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 20:13:43 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/04 14:14:33 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	char	*new_str;

	if (!s)
		return (NULL);
	i = 0;
	new_str = ft_strdup(s);
	if (!new_str)
		return (NULL);
	while (new_str[i] != '\0')
	{
		new_str[i] = f(s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
