/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   total_blocks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:30:14 by jbrinksm      #+#    #+#                 */
/*   Updated: 2019/03/25 18:30:14 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_total_blocks(t_filelst *dir_lst, t_flags *flags, char *path)
{
	int			total_blocks;
	t_filelst	*probe;
	int			print;

	print = 0;
	probe = dir_lst;
	while (probe != NULL)
	{
		if (print)
			break ;
		else if (!A_FLAG && is_browse_dir(probe->file_name))
			probe = probe->next;
		else if (!A_FLAG && probe->file_name[0] == '.')
			probe = probe->next;
		else
			print++;
	}
	if (print)
	{
		total_blocks = get_total_blocks(dir_lst, flags, path);
		ft_printf("total %i\n", total_blocks);
	}
}
