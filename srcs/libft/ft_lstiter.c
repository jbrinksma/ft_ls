/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 21:28:10 by jbrinksm      #+#    #+#                 */
/*   Updated: 2019/01/17 21:32:08 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*probe;

	probe = lst;
	f(probe);
	while (probe->next != NULL)
	{
		probe = probe->next;
		f(probe);
	}
}
