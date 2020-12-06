/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   combine_paths.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 16:08:57 by jbrinksm      #+#    #+#                 */
/*   Updated: 2019/03/25 16:08:57 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*combine_path_and_slash(char *file_name)
{
	char *result;

	if (!ft_strcmp(file_name, "/"))
		result = ft_strdup(file_name);
	else
		result = ft_strjoin(file_name, "/");
	return (result);
}
