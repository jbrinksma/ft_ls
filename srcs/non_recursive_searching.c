/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   non_recursive_searching.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 20:53:21 by jbrinksm      #+#    #+#                 */
/*   Updated: 2019/03/24 20:53:22 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	I found out that ls seperates the first list of arguments on the command
**	line. Non-dir files go first, then dirs. They are sorted and printed
**	seperately. (Also includes support for links that would point to dirs
**	but aren't printed because of 'l' flag.)
*/

void		non_recursive_starter_files(t_flags *flags, t_filelst *file_lst)
{
	t_filelst	*probe;
	t_widths	*widths;

	widths = make_t_widths();
	get_link_status(file_lst);
	get_max_width_no_dirs(file_lst, flags, widths, "");
	sort_lists(&file_lst, flags, "");
	probe = file_lst;
	while (probe != NULL)
	{
		if (!probe->is_dir || (probe->is_link && L_FLAG))
		{
			probe->is_dir = 0;
			print_dirname(file_lst, probe);
			if (!probe->permission)
				ft_error_printf("ft_ls: %s: %s\n", probe->file_name,\
				strerror(E_NOPERM));
			else
				print_file(probe, flags, "", widths);
		}
		probe = probe->next;
	}
	free(widths);
	non_recursive_starter_dirs(flags, file_lst);
}

void		non_recursive_starter_dirs(t_flags *flags,\
t_filelst *file_lst)
{
	t_filelst	*probe;
	int			printed;

	probe = file_lst;
	printed = non_dir_files_printed(file_lst);
	probe = file_lst;
	while (probe != NULL)
	{
		if (probe->is_dir)
		{
			if (printed)
				ft_putendl("");
			print_dirname(file_lst, probe);
			if (!probe->permission)
				ft_error_printf("ft_ls: %s: %s\n", probe->file_name,\
				strerror(E_NOPERM));
			else
				read_one_directory(flags, probe->file_name);
			printed++;
		}
		probe = probe->next;
	}
}
