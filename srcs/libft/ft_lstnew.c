/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 12:35:12 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/21 15:47:00 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*create;

	create = (t_list*)malloc(sizeof(t_list));
	ft_malloc_checker(create);
	if (!content)
	{
		create->content = NULL;
		create->content_size = 0;
	}
	else
	{
		create->content = malloc(sizeof(void) * content_size);
		ft_malloc_checker(create->content);
		ft_memcpy(create->content, content, content_size);
		create->content_size = content_size;
	}
	create->next = NULL;
	return (create);
}
