/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_management.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 12:03:14 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 16:04:03 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libftprintf.h"

t_flags		*make_t_flags(void)
{
	t_flags *flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	ft_malloc_checker(flags);
	L_FLAG = 0;
	A_FLAG = 0;
	T_FLAG = 0;
	REV_FLAG = 0;
	REC_FLAG = 0;
	return (flags);
}

t_widths	*make_t_widths(void)
{
	t_widths *widths;

	widths = (t_widths*)malloc(sizeof(t_widths));
	ft_malloc_checker(widths);
	SYMLINKS_LEN = 0;
	UID_LEN = 0;
	GID_LEN = 0;
	SIZE_LEN = 0;
	MAJ_DEV_LEN = 0;
	MIN_DEV_LEN = 0;
	return (widths);
}

t_filelst	*make_filelst(char *file_name, short type)
{
	t_filelst	*new_fileitem;

	new_fileitem = (t_filelst*)malloc(sizeof(t_filelst));
	ft_malloc_checker(new_fileitem);
	new_fileitem->file_name = ft_strdup(file_name);
	if (!new_fileitem->file_name)
		exit(EXIT_FAILURE);
	new_fileitem->file_mtime = 0;
	new_fileitem->temp = 0;
	new_fileitem->is_link = 0;
	new_fileitem->is_dev = 0;
	new_fileitem->is_dir = 1;
	new_fileitem->permission = 1;
	new_fileitem->total_args = 0;
	new_fileitem->error_type = type;
	new_fileitem->next = NULL;
	if (type == E_NOTDIR)
		new_fileitem->is_dir = 0;
	if (type == E_NOPERM)
		new_fileitem->permission = 0;
	return (new_fileitem);
}

void		lstadd_file(t_filelst *lst, char *file_name, short type)
{
	ft_malloc_checker(lst);
	if (ft_strlen(lst->file_name) == 0)
	{
		free(lst->file_name);
		lst->file_name = ft_strdup(file_name);
		if (type == E_NOTDIR)
			lst->is_dir = 0;
		if (type == E_NOPERM)
			lst->permission = 0;
		lst->error_type = type;
	}
	else if (lst->next)
		lstadd_file(lst->next, file_name, type);
	else
		lst->next = make_filelst(file_name, type);
}

void		free_lists(t_filelst *file_lst, t_widths *widths)
{
	t_filelst *probe;
	t_filelst *deleter;

	probe = file_lst;
	deleter = probe;
	while (probe != NULL)
	{
		probe = probe->next;
		if (deleter->file_name)
			free(deleter->file_name);
		free(deleter);
		deleter = probe;
	}
	if (widths)
		free(widths);
}
