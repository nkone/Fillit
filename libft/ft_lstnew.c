/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:30:10 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/24 16:18:11 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Allocates with malloc and returns a "fresh" link.
** The variables content and content_size of the new link are initialized
** by copy the parameters of the function. If the parameter content is nul,
** the variable content is initialized to NULL and the variable content_size
** is initialized to 0 even if the parameter content_size isn't.
** The variable next is initialized to NULL. If the allocation fails,
** return NULL.
** RETURN VALUES
** The new link.
*/

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_link;

	if (!(new_link = (t_list *)malloc(sizeof(t_list) * content_size)))
		return (NULL);
	if (content)
	{
		if (!(new_link->content = malloc(content_size)))
			return (NULL);
		ft_strncpy(new_link->content, content, content_size);
		new_link->content_size = content_size;
	}
	else
	{
		new_link->content = NULL;
		new_link->content_size = 0;
	}
	new_link->next = NULL;
	return (new_link);
}
