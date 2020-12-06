/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_revstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 20:59:07 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:13:05 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *str)
{
	char	*result;
	int		end;
	int		i;

	end = ft_strlen(str);
	result = (char*)malloc(sizeof(char) * (end + 1));
	ft_malloc_checker(result);
	i = 0;
	result[end] = '\0';
	end--;
	while (end >= 0)
	{
		result[i] = str[end];
		i++;
		end--;
	}
	free(str);
	return (result);
}
