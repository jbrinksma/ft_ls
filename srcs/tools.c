/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tools.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 16:06:31 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 12:49:38 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_browse_dir(char *dir_name)
{
	if (!ft_strcmp(dir_name, ".") || !ft_strcmp(dir_name, ".."))
		return (1);
	return (0);
}

void	print_dirname(t_filelst *file_lst, t_filelst *probe)
{
	if (probe->is_dir && (file_lst->next || file_lst->total_args > 1))
		ft_printf("%s:\n", probe->file_name);
}

void	print_error_and_dir(t_filelst *probe, char *path_with_dir, int errno)
{
	ft_printf("\n%s:\n", path_with_dir);
	ft_error_printf("ft_ls: %s: %s\n", probe->file_name,\
	strerror(errno));
}

int		non_dir_files_printed(t_filelst *file_lst)
{
	t_filelst	*probe;
	int			printed;

	probe = file_lst;
	printed = 0;
	while (probe != NULL)
	{
		if (!probe->is_dir)
			printed++;
		probe = probe->next;
	}
	return (printed);
}
