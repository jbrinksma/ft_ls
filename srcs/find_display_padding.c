/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_decision_trees.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/02 11:06:33 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 16:04:03 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Finds the padding specs which are needed for each variable-size part of
**	-l flag display format.
*/

void		min_widths_wrapper(t_filelst *probe, t_flags *flags,  \
char *file_name, t_widths *widths)
{
	char		*path_and_file;
	struct stat	stats;

	if (probe->file_name[0] == '.' && !A_FLAG)
		return ;
	path_and_file = ft_strjoin(file_name, probe->file_name);
	lstat(path_and_file, &stats);
	free(path_and_file);
	min_widths(widths, stats);
}

void		min_widths(t_widths *widths, struct stat stats)
{
	struct passwd	*passwds;
	struct group	*groups;
	int				len;

	passwds = getpwuid(stats.st_uid);
	groups = getgrgid(stats.st_gid);
	len = ft_longlonglen(stats.st_nlink);
	if (len > SYMLINKS_LEN)
		SYMLINKS_LEN = len;
	if (passwds)
		len = ft_strlen(passwds->pw_name);
	else
		len = ft_intlen(stats.st_uid);
	if (len > UID_LEN)
		UID_LEN = len;
	if (groups)
		len = ft_strlen(groups->gr_name);
	else
		len = ft_intlen(stats.st_gid);
	if (len > GID_LEN)
		GID_LEN = len;
	len = ft_longlonglen(stats.st_size);
	if (len > SIZE_LEN)
		SIZE_LEN = len;
	dev_width(widths, stats);
}

void		dev_width(t_widths *widths, struct stat stats)
{
	int	len;
	int	maj_dev;
	int	min_dev;

	maj_dev = major(stats.st_rdev);
	min_dev = minor(stats.st_rdev);
	if (!maj_dev)
		len = 0;
	else
		len = ft_longlonglen(maj_dev);
	if (!min_dev)
		len = 0;
	else
		len = ft_longlonglen(min_dev);
	if (len > MAJ_DEV_LEN)
		MAJ_DEV_LEN = len;
	if (len > MIN_DEV_LEN)
		MIN_DEV_LEN = len;
}
