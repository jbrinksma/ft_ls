/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   l_flag_function.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 19:10:36 by jbrinksm      #+#    #+#                 */
/*   Updated: 2019/03/24 19:10:37 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Main hub for gathering all information needed about the file in order
**	to display it in -l format.
*/

void	l_flag_function(t_filelst *probe, char *file_name, t_widths *widths)
{
	struct stat		stats;
	char			*temp;

	lstat(file_name, &stats);
	temp = mode_to_string(probe, stats.st_mode);
	ft_printf("%s  ", temp);
	ft_printf("%*d ", SYMLINKS_LEN, stats.st_nlink);
	l_flag_username(widths, stats);
	l_flag_groupname(widths, stats);
	l_flag_devnum_or_size(probe, widths, stats);
	l_flag_time(stats);
	free(temp);
}

void	l_flag_username(t_widths *widths, struct stat stats)
{
	struct passwd	*passwds;
	char			*temp;

	passwds = getpwuid(stats.st_uid);
	if (passwds)
		ft_printf("%-*s  ", UID_LEN, passwds->pw_name);
	else
	{
		temp = ft_itoa(stats.st_uid);
		ft_printf("%-*s  ", UID_LEN, temp);
		free(temp);
	}
}

void	l_flag_groupname(t_widths *widths, struct stat stats)
{
	struct group	*groups;
	char			*temp;

	groups = getgrgid(stats.st_gid);
	if (groups)
		ft_printf("%-*s ", GID_LEN, groups->gr_name);
	else
	{
		temp = ft_itoa(stats.st_gid);
		ft_printf("%-*s ", GID_LEN, temp);
		free(temp);
	}
}

void	l_flag_devnum_or_size(t_filelst *probe, t_widths *widths,\
struct stat stats)
{
	if (probe->is_dev)
		ft_printf(" %*d, %*d ", MAJ_DEV_LEN, major(stats.st_rdev),\
		MIN_DEV_LEN, minor(stats.st_rdev));
	else
	{
		if (MAJ_DEV_LEN)
			ft_printf("   %*lld ", MAJ_DEV_LEN + MIN_DEV_LEN, stats.st_size);
		else
			ft_printf(" %*lld ", SIZE_LEN, stats.st_size);
	}
}

void	l_flag_time(struct stat stats)
{
	char			*s_time;
	time_t			current_time;

	time(&current_time);
	if (current_time == -1)
		exit(EXIT_FAILURE);
	s_time = ctime(&stats.st_mtime);
	if (current_time - stats.st_mtime <= 15724800 &&\
	current_time - stats.st_mtime >= -15724800)
		ft_printf("%.12s ", s_time + 4);
	else
		ft_printf("%.6s % 5s ", s_time + 4, ft_findnword(s_time, 5));
}
