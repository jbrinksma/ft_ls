/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   recursive_searching.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 17:24:48 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/20 16:57:58 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	I found out that ls seperates the first list of arguments on the command
**	line. Non-dir files go first, then dirs. They are sorted and printed
**	seperately. (Also includes support for links that would point to dirs
**	but aren't printed because of 'l' flag.)
*/

void	recursive_starter_files(t_flags *flags, t_filelst *file_lst)
{
	t_filelst		*probe;
	t_widths		*widths;

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
	recursive_starter_dirs(flags, file_lst);
}

void	recursive_starter_dirs(t_flags *flags, t_filelst *file_lst)
{
	t_filelst		*probe;
	int				printed;
	char			*path;
	DIR				*dir_opened;

	probe = file_lst;
	printed = non_dir_files_printed(file_lst);
	get_link_status(file_lst);
	while (probe != NULL)
	{
		if (probe->is_dir)
		{
			if (printed)
				ft_putendl("");
			print_dirname(file_lst, probe);
			path = combine_path_and_slash(probe->file_name);
			dir_opened = opendir(probe->file_name);
			recursive_finder(flags, dir_opened, path);
			closedir(dir_opened);
			free(path);
			printed++;
		}
		probe = probe->next;
	}
}

/*
**	After first list of filenames is handled, This function will be used
**	to go deep into the directory tree. It will read the dir opened and
**	remember the whole path to the dir.
*/

void	recursive_finder(t_flags *flags, DIR *dir_opened, char *path)
{
	struct dirent	*dir_content;
	t_filelst		*file_lst;
	t_filelst		*probe;
	t_widths		*widths;

	widths = make_t_widths();
	dir_content = readdir(dir_opened);
	file_lst = make_filelst("", E_NOERROR);
	while (dir_content != NULL)
	{
		lstadd_file(file_lst, dir_content->d_name, E_NOERROR);
		dir_content = readdir(dir_opened);
	}
	sort_lists(&file_lst, flags, path);
	if (L_FLAG)
		prepare_l_flag(file_lst, flags, path, widths);
	read_list_of_files(file_lst, flags, path, widths);
	probe = file_lst;
	while (probe != NULL)
	{
		read_and_open_dirs(probe, flags, dir_opened, path);
		probe = probe->next;
	}
	free_lists(file_lst, widths);
}
