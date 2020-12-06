/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_stuff.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 19:42:11 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 11:40:20 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libftprintf.h"

/*
**  Sorts list for all possible flags.
**	Buy-one-get-all sorter.
*/

void		sort_lists(t_filelst **file_lst, t_flags *flags, char *path)
{
	t_filelst	*probe;
	struct stat	stats;
	char		*path_and_file;
	int			i;

	probe = *file_lst;
	i = 0;
	while (probe != NULL)
	{
		if (T_FLAG)
		{
			path_and_file = ft_strjoin(path, probe->file_name);
			lstat(path_and_file, &stats);
			free(path_and_file);
			probe->file_mtime = stats.st_mtime;
		}
		probe = probe->next;
		i++;
	}
	while (i > 0)
	{
		probe = (*file_lst)->next;
		sort_lists_continued(flags, file_lst, probe);
		i--;
	}
}

void		sort_lists_continued(t_flags *flags, t_filelst **file_lst,\
t_filelst *probe)
{
	int time_cmp;
	int	str_cmp;

	if (*file_lst && probe)
	{
		str_cmp = ft_strcmp(FILE_NAME, NEXT_FILE_NAME);
		time_cmp = FILE_MTIME - NEXT_FILE_MTIME;
		if ((!REV_FLAG && T_FLAG && time_cmp < 0)\
		|| (REV_FLAG && T_FLAG && time_cmp > 0)\
		|| (!REV_FLAG && !T_FLAG && str_cmp > 0)\
		|| (REV_FLAG && !T_FLAG && str_cmp < 0)\
		|| (!REV_FLAG && T_FLAG && !time_cmp && str_cmp > 0)\
		|| (REV_FLAG && T_FLAG && !time_cmp && str_cmp < 0))
		{
			probe = *file_lst;
			*file_lst = probe->next;
			probe->next = (*file_lst)->next;
			(*file_lst)->next = probe;
		}
		sort_lists_continued(flags, &(*file_lst)->next, probe->next);
	}
}

/*
**	Non-existing files can only be sorted on name
**	therefore I made a seperate quick sorter.
*/

void		sort_errors(t_filelst **error_file_lst)
{
	t_filelst	*probe;
	int			i;

	probe = *error_file_lst;
	i = 0;
	while (probe != NULL)
	{
		probe = probe->next;
		i++;
	}
	while (i > 0)
	{
		probe = (*error_file_lst)->next;
		sort_errors_continued(error_file_lst, probe);
		i--;
	}
}

void		sort_errors_continued(t_filelst **error_file_lst, t_filelst *probe)
{
	int	str_cmp;

	if (*error_file_lst && probe)
	{
		str_cmp = ft_strcmp((*error_file_lst)->file_name, probe->file_name);
		if (str_cmp > 0)
		{
			probe = *error_file_lst;
			*error_file_lst = probe->next;
			probe->next = (*error_file_lst)->next;
			(*error_file_lst)->next = probe;
		}
		sort_errors_continued(&(*error_file_lst)->next, probe->next);
	}
}
