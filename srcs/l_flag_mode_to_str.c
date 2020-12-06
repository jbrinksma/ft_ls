/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   l_flag_mode_to_str.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 19:11:42 by jbrinksm      #+#    #+#                 */
/*   Updated: 2019/03/24 19:11:43 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Basically here I translate the file mode integer into a string in the
**	rwx format (also S,T and all the different types of files.)
*/

char		*mode_to_string(t_filelst *probe, mode_t mode)
{
	char	*mode_str;
	mode_t	calc;

	mode_str = ft_strnew(11);
	calc = (mode_t)49152;
	while (mode_str[0] == '\0')
	{
		calc -= 1024;
		if (S_ISSOCK(mode) && calc == S_IFSOCK)
			mode_str[0] = 's';
		else if (S_ISLNK(mode) && calc == S_IFLNK)
			mode_str[0] = 'l';
		else if (S_ISREG(mode) && calc == S_IFREG)
			mode_str[0] = '-';
		else if (S_ISBLK(mode) && calc == S_IFBLK)
			mode_str[0] = 'b';
		else if (S_ISDIR(mode) && calc == S_IFDIR)
			mode_str[0] = 'd';
		else if (S_ISCHR(mode) && calc == S_IFCHR)
			mode_str[0] = 'c';
		else if (S_ISFIFO(mode) && calc == S_IFIFO)
			mode_str[0] = 'p';
	}
	mode_modify_file_type(probe, mode_str);
	return (mode_to_string2(mode_str, mode, calc));
}

void		mode_modify_file_type(t_filelst *probe, char *mode_str)
{
	if (mode_str[0] == 'c' || mode_str[0] == 'b')
		probe->is_dev = 1;
	else if (mode_str[0] == 'l')
		probe->is_link = 1;
}

char		*mode_to_string2(char *mode_str, mode_t mode, mode_t calc)
{
	int		specials[3];

	mode -= calc;
	specials[0] = 0;
	specials[1] = 0;
	specials[2] = 0;
	if (S_ISUID & mode)
	{
		specials[0] = 1;
		mode -= S_ISUID;
	}
	if (S_ISGID & mode)
	{
		specials[1] = 1;
		mode -= S_ISGID;
	}
	if (S_ISVTX & mode)
	{
		specials[2] = 1;
		mode -= S_ISVTX;
	}
	return (mode_to_string3(mode_str, mode, specials));
}

char		*mode_to_string3(char *mode_str, mode_t mode, int *specials)
{
	mode_t	calc;
	int		i;

	calc = 256;
	i = 1;
	while (i < 10)
	{
		if (mode & calc)
		{
			mode_to_string4(&mode_str, specials, i);
			mode -= calc;
		}
		else if ((i == 3 && specials[0]) || (i == 6 && specials[1]))
			mode_str[i] = 'S';
		else if (i == 9 && specials[2])
			mode_str[i] = 'T';
		else
			mode_str[i] = '-';
		if (1 % 3 != 0)
			calc /= 2;
		else
			calc /= 10;
		i++;
	}
	return (mode_str);
}

void		mode_to_string4(char **mode_str, int *specials, int i)
{
	if (i == 1 || i == 4 || i == 7)
		(*mode_str)[i] = 'r';
	else if (i == 2 || i == 5 || i == 8)
		(*mode_str)[i] = 'w';
	else if (i == 3 || i == 6 || i == 9)
	{
		if ((i == 3 && specials[0]) || (i == 6 && specials[1]))
			(*mode_str)[i] = 's';
		else if (i == 9 && specials[2])
			(*mode_str)[i] = 't';
		else
			(*mode_str)[i] = 'x';
	}
}
