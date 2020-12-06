/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 09:13:15 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:13:05 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	if_n_greater_zero(char **strint, int *n, int *len)
{
	(*strint)[*len] = *n % 10 + 48;
	(*len)--;
	*n /= 10;
}

static char	*ft_allocintmin(void)
{
	char	*min;

	min = ft_strdup("-2147483648");
	return (min);
}

char		*ft_itoa(int n)
{
	char	*strint;
	int		i;
	int		len;

	i = 0;
	len = ft_intlen(n);
	strint = (char*)malloc((ft_intlen(n) + 1) * sizeof(char));
	ft_malloc_checker(strint);
	if (n == -2147483648)
		return (ft_allocintmin());
	else if (n < 0)
	{
		strint[i] = '-';
		n *= -1;
	}
	strint[len] = '\0';
	len--;
	if (n == 0)
		strint[len] = 0 + 48;
	while (n > 0)
		if_n_greater_zero(&strint, &n, &len);
	return (strint);
}
