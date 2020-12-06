/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 18:00:41 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:58:34 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Sort the files before error output.
*/

void		print_errors(t_filelst *error_file_lst)
{
	t_filelst *probe;

	sort_errors(&error_file_lst);
	probe = error_file_lst;
	while (probe != NULL)
	{
		ft_error_printf("ft_ls: %s: %s\n", probe->file_name,\
		strerror(probe->error_type));
		probe = probe->next;
	}
}

/*
**	Check input for possible fatal errors.
**	Check if we print arguments or just current dir (no args)
**	Send list over to either recursive or non-recursive reader.
*/

int			main(int argc, char **argv)
{
	t_flags		*flags;
	t_filelst	*arg_file_lst;
	t_filelst	*error_file_lst;

	(void)argc;
	arg_file_lst = make_filelst("", E_NOERROR);
	error_file_lst = make_filelst("", E_NOERROR);
	flags = make_t_flags();
	if (!arg_reader(argv, flags, arg_file_lst, error_file_lst))
		lstadd_file(arg_file_lst, ".", E_NOERROR);
	if (REC_FLAG)
		recursive_starter_files(flags, arg_file_lst);
	else
		non_recursive_starter_files(flags, arg_file_lst);
	free_lists(arg_file_lst, NULL);
	free(flags);
	return (EXIT_SUCCESS);
}
