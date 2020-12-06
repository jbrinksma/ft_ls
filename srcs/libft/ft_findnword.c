/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_findnword.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 21:19:56 by jbrinksm      #+#    #+#                 */
/*   Updated: 2019/03/21 21:19:57 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	delimit_word(char *str, int i)
{
	while (!ft_isspace(str[i]))
		i++;
	str[i] = '\0';
}

char		*ft_findnword(char *str, int n)
{
	int i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
		{
			while (ft_isspace(str[i]))
				i++;
		}
		else
		{
			counter++;
			if (counter == n)
			{
				delimit_word(str, i);
				return (&str[i]);
			}
			while (!ft_isspace(str[i]))
				i++;
		}
	}
	return (str);
}
