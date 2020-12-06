/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_info.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 20:10:48 by jbrinksm      #+#    #+#                 */
/*   Updated: 2019/03/24 20:10:48 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Checks whole file_list for link status.
**	This is needed for some display decisions happening before the
**	-l flag function is called.
*/

void	get_link_status(t_filelst *file_lst)
{
	struct stat	stats;
	t_filelst	*probe;

	probe = file_lst;
	while (probe != NULL)
	{
		lstat(probe->file_name, &stats);
		if (S_ISLNK(stats.st_mode))
			probe->is_link = 1;
		probe = probe->next;
	}
}

/*
**	saves the largest padding of each variable-size part of the -l
**	flag display, of the entire list.
*/

void	get_max_width(t_filelst *dir_lst, t_flags *flags, t_widths *widths,\
char *path)
{
	t_filelst	*probe;

	probe = dir_lst;
	while (probe != NULL)
	{
		min_widths_wrapper(probe, flags, path, widths);
		probe = probe->next;
	}
}

void	get_max_width_no_dirs(t_filelst *dir_lst, t_flags *flags,\
t_widths *widths, char *path)
{
	t_filelst	*probe;

	probe = dir_lst;
	while (probe != NULL)
	{
		if (!probe->is_dir)
			min_widths_wrapper(probe, flags, path, widths);
		probe = probe->next;
	}
}

int		get_total_blocks(t_filelst *dir_lst, t_flags *flags,\
char *file_name)
{
	struct stat	stats;
	char		*path_and_file;
	t_filelst	*probe;
	int			total_blocks;

	probe = dir_lst;
	total_blocks = 0;
	while (probe != NULL)
	{
		if (!(probe->file_name[0] == '.' && !A_FLAG))
		{
			path_and_file = ft_strjoin(file_name, probe->file_name);
			lstat(path_and_file, &stats);
			free(path_and_file);
			total_blocks += stats.st_blocks;
		}
		probe = probe->next;
	}
	return (total_blocks);
}
