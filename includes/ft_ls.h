/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 18:01:08 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 16:07:18 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define FUNCT_FAILURE 0
# define FUNCT_SUCCESS 1
# define E_NOTFILE 2
# define E_NOTDIR 20
# define E_NOPERM 13
# define E_NOERROR 0

# define NO_ARGS 0

# define NEXT_FILE_MTIME (*file_lst)->next->file_mtime
# define FILE_MTIME (*file_lst)->file_mtime
# define NEXT_FILE_NAME (*file_lst)->next->file_name
# define FILE_NAME (*file_lst)->file_name

# define REC_FLAG flags->rec_flag
# define REV_FLAG flags->r_flag
# define T_FLAG flags->t_flag
# define A_FLAG flags->a_flag
# define L_FLAG flags->l_flag

# define SYMLINKS_LEN widths->l_width
# define UID_LEN widths->u_width
# define GID_LEN widths->g_width
# define SIZE_LEN widths->s_width
# define MAJ_DEV_LEN widths->m_width1
# define MIN_DEV_LEN widths->m_width2

# include "libft.h"
# include "libftprintf.h"
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

/*
**	write
**	opendir readdir closedir
**	lstat
**	getpwuid
**	getgrgid
**	listxattr getxattr
**	ctime
**	malloc free exit
**	perror
**	strerror
*/

/*
**	This struct is used for all types of lists
**	(error lists, file lists, dir lists and
**	combined lists.)
*/

typedef struct	s_filelst
{
	char				*file_name;
	long				file_mtime;
	long				temp;
	char				is_link;
	char				is_dev;
	char				is_dir;
	char				permission;
	int					total_args;
	int					error_type;
	struct s_filelst	*next;
}				t_filelst;

/*
**	Struct to save flags. Is made once and is
**	used for the entire duration of the program.
*/

typedef struct	s_flags
{
	int			l_flag;
	int			rec_flag;
	int			a_flag;
	int			r_flag;
	int			t_flag;
}				t_flags;

/*
**	Struct is used to save biggest width of
**	each variable-size part of -l flag format.
*/

typedef struct	s_widths
{
	int			l_width;
	int			u_width;
	int			g_width;
	int			s_width;
	int			m_width1;
	int			m_width2;
}				t_widths;

/*
**	main.c
*/

void			print_errors(t_filelst *error_file_lst);

/*
**  struct_management.c
*/

t_flags			*make_t_flags(void);
t_widths		*make_t_widths(void);
t_filelst		*make_filelst(char *file_name, short type);
void			lstadd_file(t_filelst *lst, char *file_name, short type);
void			free_lists(t_filelst *file_lst, t_widths *widths);

/*
** input_handler.c
*/

int				arg_reader(char **argv, t_flags *flags, t_filelst \
				*dir_content, t_filelst *error_file_lst);
int				check_flags(char *arg, t_flags *flags);
int				add_files(char **argv, t_filelst *arg_file_lst, int argv_index,\
				t_filelst *error_file_lst);
int				test_and_add_file(char *arg, t_filelst *arg_file_lst,\
				t_filelst *error_file_lst);
int				is_arg_link(char *arg);

/*
**	non_recursive_searching.c
*/

void			non_recursive_starter_files(t_flags *flags, \
				t_filelst *file_lst);
void			non_recursive_starter_dirs(t_flags *flags, \
				t_filelst *file_lst);

/*
**  recursive_searching.c
*/

void			recursive_starter_files(t_flags *flags, t_filelst *file_lst);
void			recursive_starter_dirs(t_flags *flags, t_filelst *file_lst);
void			recursive_finder(t_flags *flags, DIR *dir_opened, \
				char *path);

/*
**  file_reading.c
*/

void			print_file(t_filelst *probe, t_flags *flags, char *path, \
				t_widths *widths);
void			prepare_l_flag(t_filelst *dir_lst, t_flags *flags, \
				char *path, t_widths *widths);
void			read_list_of_files(t_filelst *dir_lst, t_flags *flags, \
				char *path, t_widths *widths);
void			read_one_directory(t_flags *flags, char *path);
void			read_and_open_dirs(t_filelst *probe, t_flags *flags, \
				DIR *dir_opened, char *path);

/*
**	l_flag_function.c
*/

void			l_flag_function(t_filelst *probe, char *file_name, \
				t_widths *widths);
void			l_flag_username(t_widths *widths, struct stat stats);
void			l_flag_groupname(t_widths *widths, struct stat stats);
void			l_flag_devnum_or_size(t_filelst *probe, t_widths *widths, \
				struct stat stats);
void			l_flag_time(struct stat stats);

/*
**	l_flag_mode_to_str.c
*/

char			*mode_to_string(t_filelst *probe, mode_t mode);
char			*mode_to_string2(char *mode_str, mode_t mode, mode_t calc);
char			*mode_to_string3(char *mode_str, mode_t mode, int *specials);
void			mode_modify_file_type(t_filelst *probe, char *mode_str);
void			mode_to_string4(char **mode_str, int *specials, int i);

/*
**  find_display_padding.c
*/

void			dev_width(t_widths *widths, struct stat stats);
void			min_widths(t_widths *widths, struct stat stats);
void			min_widths_wrapper(t_filelst *probe, t_flags *flags, \
				char *file_name, t_widths *widths);

/*
**  tools.c
*/

void			print_filelst(t_filelst *lst);
int				is_browse_dir(char *dir_name);
void			print_dirname(t_filelst *file_lst, t_filelst *probe);
void			print_error_and_dir(t_filelst *probe, char *path_with_dir, \
				int errno);
int				non_dir_files_printed(t_filelst *file_lst);

/*
**  sorting_stuff.c
*/

void			sort_lists(t_filelst **file_lst, t_flags *flags, \
				char *path);
void			sort_lists_continued(t_flags *args, t_filelst **file_lst, \
				t_filelst *probe);
void			sort_errors(t_filelst **error_file_lst);
void			sort_errors_continued(t_filelst **error_file_lst, \
				t_filelst *probe);

/*
**	get_info.c
*/

void			get_max_width(t_filelst *dir_lst, t_flags *flags, \
				t_widths *widths, char *path);
void			get_max_width_no_dirs(t_filelst *dir_lst, t_flags *flags, \
				t_widths *widths, char *path);
int				get_total_blocks(t_filelst *dir_lst, t_flags *flags,\
				char *file_name);
void			get_link_status(t_filelst *file_lst);

/*
**	combine_paths.c
*/

char			*combine_path_and_slash(char *file_name);

/*
**	print_total_blocks.c
*/

void			print_total_blocks(t_filelst *dir_lst, t_flags *flags, \
				char *path);

#endif
