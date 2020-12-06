/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_reading.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 13:43:38 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/20 19:25:39 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Before l_flag is executed I check the padding for display and print total
**	blocks when necessary.
*/

void	prepare_l_flag(t_filelst *dir_lst, t_flags *flags, char *path, \
t_widths *widths)
{
	get_max_width(dir_lst, flags, widths, path);
	print_total_blocks(dir_lst, flags, path);
}

void	read_list_of_files(t_filelst *dir_lst, t_flags *flags, \
char *path, t_widths *widths)
{
	t_filelst	*probe;

	probe = dir_lst;
	while (probe != NULL)
	{
		print_file(probe, flags, path, widths);
		probe = probe->next;
	}
}

/*
**	Main function for reading and printing all files.
*/

void	print_file(t_filelst *probe, t_flags *flags, char *path, \
t_widths *widths)
{
	char	*path_and_file;
	char	*link_buf;

	if (probe->file_name[0] != '.' || A_FLAG)
	{
		if (L_FLAG)
		{
			path_and_file = ft_strjoin(path, probe->file_name);
			l_flag_function(probe, path_and_file, widths);
			free(path_and_file);
			if (probe->is_link)
			{
				link_buf = ft_strnew(500);
				readlink(path_and_file, link_buf, 500);
				ft_printf("%s -> %s\n", probe->file_name, link_buf);
				free(link_buf);
			}
			else
				ft_printf("%s\n", probe->file_name);
		}
		else
			ft_printf("%s\n", probe->file_name);
	}
}

/*
**	Used for non-recursive instances of ft_ls where only one layer
**	of the directory tree has to be read.
*/

void	read_one_directory(t_flags *flags, char *path)
{
	struct dirent	*dir_content;
	DIR				*dir_opened;
	t_filelst		*file_lst;
	t_widths		*widths;
	char			*path_with_slash;

	widths = make_t_widths();
	dir_opened = opendir(path);
	dir_content = readdir(dir_opened);
	file_lst = make_filelst("", E_NOERROR);
	path_with_slash = combine_path_and_slash(path);
	while (dir_content != NULL)
	{
		lstadd_file(file_lst, dir_content->d_name, E_NOERROR);
		dir_content = readdir(dir_opened);
	}
	sort_lists(&file_lst, flags, path_with_slash);
	if (L_FLAG)
		prepare_l_flag(file_lst, flags, path_with_slash, widths);
	read_list_of_files(file_lst, flags, path_with_slash, widths);
	free(path_with_slash);
	free_lists(file_lst, widths);
	closedir(dir_opened);
}

/*
**	Used for recursive instances of ft_ls where we have to print and
**	read every dir we find. Will return dirs to recursive_finder.
*/

void	read_and_open_dirs(t_filelst *probe, t_flags *flags, \
DIR *dir_opened, char *path)
{
	char			*path_with_dir;
	char			*path_with_dir_and_slash;
	extern int		errno;

	errno = 0;
	path_with_dir = ft_strjoin(path, probe->file_name);
	path_with_dir_and_slash = combine_path_and_slash(path_with_dir);
	dir_opened = opendir(path_with_dir_and_slash);
	if (dir_opened != NULL)
	{
		if (!is_browse_dir(probe->file_name) && (probe->file_name[0] != '.'\
		|| A_FLAG) && !is_arg_link(path_with_dir))
		{
			ft_printf("\n%s:\n", path_with_dir);
			recursive_finder(flags, dir_opened, path_with_dir_and_slash);
		}
		closedir(dir_opened);
	}
	else if (errno == E_NOPERM && (probe->file_name[0] != '.' \
	|| A_FLAG) && !is_arg_link(path_with_dir))
		print_error_and_dir(probe, path_with_dir, errno);
	free(path_with_dir);
	free(path_with_dir_and_slash);
}
