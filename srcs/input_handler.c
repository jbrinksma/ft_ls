/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 12:00:09 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 17:07:47 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			check_flags(char *arg, t_flags *flags)
{
	int i;

	i = 1;
	while (arg[i] != '\0')
	{
		if (arg[i] == 'l')
			L_FLAG = 1;
		else if (arg[i] == 'R')
			REC_FLAG = 1;
		else if (arg[i] == 'a')
			A_FLAG = 1;
		else if (arg[i] == 'r')
			REV_FLAG = 1;
		else if (arg[i] == 't')
			T_FLAG = 1;
		else
		{
			ft_error_printf("./ft_ls: illegal option -- %c\nusage: ft_ls \
[-Ralrt] [file ...]\n", (char)arg[i]);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (FUNCT_SUCCESS);
}

/*
**	Quick link check which is handy before some link-to-dir situations.
*/

int			is_arg_link(char *arg)
{
	struct stat	stats;

	lstat(arg, &stats);
	if (S_ISLNK(stats.st_mode))
		return (1);
	else
		return (0);
}

/*
**	Checks if file exists and if it is a dir and then goes
**	on to check errors like no permission. Will always add
**	filename to either error_list or arg_list because it has
**	to be sorted afterwards either way.
*/

int			test_and_add_file(char *arg, t_filelst *arg_file_lst,\
t_filelst *error_file_lst)
{
	DIR				*dir_opened;
	extern int		errno;

	errno = 0;
	dir_opened = opendir(arg);
	arg_file_lst->total_args += 1;
	if (dir_opened == NULL)
	{
		if (errno == E_NOTDIR || (errno == E_NOTFILE && is_arg_link(arg)))
			lstadd_file(arg_file_lst, arg, E_NOTDIR);
		else if (errno == E_NOPERM)
			lstadd_file(arg_file_lst, arg, E_NOPERM);
		else
		{
			lstadd_file(error_file_lst, arg, errno);
			return (FUNCT_FAILURE);
		}
	}
	else
	{
		lstadd_file(arg_file_lst, arg, E_NOERROR);
		closedir(dir_opened);
	}
	return (FUNCT_SUCCESS);
}

int			add_files(char **argv, t_filelst *arg_file_lst, int argv_index,\
t_filelst *error_file_lst)
{
	int				valid_args;

	valid_args = 0;
	while (argv[argv_index] != NULL)
	{
		valid_args += test_and_add_file(argv[argv_index], arg_file_lst,\
		error_file_lst);
		argv_index++;
	}
	if (ft_strcmp("", error_file_lst->file_name))
		print_errors(error_file_lst);
	if (!valid_args)
		exit(EXIT_FAILURE);
	return (FUNCT_SUCCESS);
}

/*
**	First checks flags and makes sure to handle the '--' end of command
**	and make sure we are still looking at flags. Then checks the possible
**	file arguments.
*/

int			arg_reader(char **argv, t_flags *flags, t_filelst *arg_file_lst,\
t_filelst *error_file_lst)
{
	int	argv_index;
	int	return_value;

	argv_index = 1;
	return_value = 0;
	while (argv[argv_index] != NULL && argv[argv_index][0] == '-')
	{
		if (!ft_strcmp(argv[argv_index], "-"))
			break ;
		else if (!ft_strcmp(argv[argv_index], "--"))
		{
			argv_index++;
			break ;
		}
		check_flags(argv[argv_index], flags);
		argv_index++;
	}
	if (argv[argv_index] == NULL)
		return (NO_ARGS);
	add_files(argv, arg_file_lst, argv_index, error_file_lst);
	return (FUNCT_SUCCESS);
}
