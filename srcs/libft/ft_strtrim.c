/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 22:33:10 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/04 14:18:33 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim_end_and_return(const char *s, int start, int end, int i)
{
	char *str;

	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	str = (char*)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		exit(EXIT_FAILURE);
	while (start <= end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_returnempty(void)
{
	char *str;

	str = (char*)malloc(sizeof(char) * (1));
	if (!str)
		exit(EXIT_FAILURE);
	str[0] = '\0';
	return (str);
}

char		*ft_strtrim(const char *s)
{
	int		start;
	int		end;
	char	*result;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return (ft_returnempty());
	else
	{
		result = ft_trim_end_and_return(s, start, end, i);
		return (result);
	}
}
