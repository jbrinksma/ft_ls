/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 22:21:29 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:13:05 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		i2;
	char	*join;

	if (!s1 || !s2)
		exit(EXIT_FAILURE);
	i = 0;
	i2 = 0;
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	ft_malloc_checker(join);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
	{
		join[i] = s2[i2];
		i++;
		i2++;
	}
	join[i] = '\0';
	free(s1);
	free(s2);
	return (join);
}
