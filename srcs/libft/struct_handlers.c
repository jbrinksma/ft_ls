/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_handlers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/07 10:58:00 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:47:56 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	Like the name suggests: this file contains all struct initializer functions.
*/

t_va_list	*make_va_item(void)
{
	t_va_list	*new_item;

	new_item = (t_va_list*)malloc(sizeof(t_va_list));
	ft_malloc_checker(new_item);
	new_item->data_double = 0;
	new_item->data_ptr = 0;
	new_item->data_type = -1;
	new_item->flag_hash = 0;
	new_item->flag_zero = 0;
	new_item->flag_minus = 0;
	new_item->flag_space = 0;
	new_item->flag_plus = 0;
	new_item->field_width = 0;
	new_item->precision = -1;
	new_item->length_mod = -1;
	new_item->removed_minus = 0;
	new_item->is_positive = -1;
	new_item->is_empty = 0;
	new_item->empty_char_index = -1;
	new_item->end_of_str = -1;
	new_item->next = NULL;
	return (new_item);
}

t_va_list	*add_item_va_list(t_va_list *data_list)
{
	if (data_list->next == NULL)
	{
		data_list->next = make_va_item();
		return (data_list->next);
	}
	else
	{
		return (add_item_va_list(data_list->next));
	}
}

t_va_list	*last_item(t_va_list *data_list)
{
	if (data_list->next == NULL)
		return (data_list);
	else
		return (last_item(data_list->next));
}

void		clear_list(t_va_list *data_list)
{
	t_va_list *probe;
	t_va_list *deleter;

	probe = data_list;
	deleter = probe;
	while (probe != NULL)
	{
		probe = probe->next;
		free(deleter);
		deleter = probe;
	}
}
