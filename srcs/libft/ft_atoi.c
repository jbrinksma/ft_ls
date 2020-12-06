/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 13:36:14 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 14:58:35 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_returner(long long result, int min)
{
	if (min == -1)
	{
		if (result * -1 < -2147483648)
			return (0);
	}
	else if (result > 2147483647)
		return (0);
	return (result * min);
}

int			ft_atoi(const char *str)
{
	int			i;
	long long	result;
	int			min;

	min = 1;
	i = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-')
		min = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (ft_atoi_returner(result, min));
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (ft_atoi_returner(result, min));
}
