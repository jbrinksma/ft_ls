/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 16:22:56 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/01/17 20:25:39 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*probe;
	t_list	*deleter;

	probe = *alst;
	while (probe->next != NULL)
	{
		deleter = probe;
		probe = probe->next;
		del(deleter->content, deleter->content_size);
		free(deleter);
		deleter = NULL;
	}
	del(probe->content, probe->content_size);
	free(probe);
	*alst = NULL;
}
