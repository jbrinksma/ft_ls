/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_countwords.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 11:05:02 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/04 12:42:35 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(const char *str, char delimiter)
{
	int i;
	int word_count;
	int word_trigger;

	i = 0;
	word_count = 0;
	word_trigger = 1;
	while (str[i] != '\0')
	{
		if (str[i] != delimiter)
		{
			if (word_trigger)
			{
				word_count++;
				word_trigger = 0;
			}
		}
		if (str[i] == delimiter)
			word_trigger = 1;
		i++;
	}
	return (word_count);
}
