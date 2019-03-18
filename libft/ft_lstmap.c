/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:56:04 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/24 15:56:06 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Iterates a list lst and applies the function f to each link to create
** a "fresh" list using malloc() resulting from successive applications of f.
** If the allocation fails, the function returns NULL.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;

	if (!lst)
		return (NULL);
	else
	{
		new_list = f(lst);
		new_list->next = ft_lstmap(lst->next, f);
	}
	return (new_list);
}
