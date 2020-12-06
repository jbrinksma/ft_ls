/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 08:38:24 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/04 14:20:52 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	make_word(const char *s, char c, char **array, int *strsplit_indxs)
{
	while (s[S_INDEX] != c && s[S_INDEX] != '\0')
	{
		array[ARRAY_Y][ARRAY_X] = s[S_INDEX];
		ARRAY_X++;
		S_INDEX++;
	}
	if (s[S_INDEX] != '\0' || (s[S_INDEX] == '\0' && s[S_INDEX - 1] != c))
	{
		array[ARRAY_Y][ARRAY_X] = '\0';
		ARRAY_Y++;
	}
	ARRAY_X = 0;
	array[ARRAY_Y] = 0;
}

char		**ft_strsplit(const char *s, char c)
{
	int		strsplit_indxs[3];
	char	**array;
	int		words;
	int		word_length;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	S_INDEX = 0;
	ARRAY_Y = 0;
	ARRAY_X = 0;
	array = (char**)malloc(sizeof(char*) * (words + 1));
	if (array == 0)
		exit(EXIT_FAILURE);
	while (s[S_INDEX] != '\0')
	{
		while (s[S_INDEX] == c && s[S_INDEX] != '\0')
			S_INDEX++;
		word_length = ft_wordlength(&s[S_INDEX], c);
		array[ARRAY_Y] = (char*)malloc(sizeof(char) * (word_length + 1));
		if (array[ARRAY_Y] == 0)
			exit(EXIT_FAILURE);
		make_word(s, c, array, strsplit_indxs);
	}
	return (array);
}
