/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lltoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 09:13:15 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:13:05 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	if_n_greater_zero(char **strint, long long *n, int *len)
{
	(*strint)[*len] = *n % 10 + 48;
	(*len)--;
	*n /= 10;
}

static char	*ft_alloclonglongmin(void)
{
	char	*min;

	min = ft_strdup("-9223372036854775808");
	return (min);
}

char		*ft_lltoa(long long n)
{
	char	*strint;
	int		i;
	int		len;

	i = 0;
	len = ft_longlonglen(n);
	strint = (char*)malloc((ft_longlonglen(n) + 1) * sizeof(char));
	ft_malloc_checker(strint);
	if (n == -9223372036854775807 - 1)
		return (ft_alloclonglongmin());
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
