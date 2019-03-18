/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:17:51 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/24 16:17:20 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Takes as a parameter a link's pointer address and frees the memory
** of the link's content using the function del given as a parameter,
** the frees the link's memory using free(). The memory of next must not be
** freed under any circumstance. Finally, the pointer to the link that was
** just freed must be set next to NULL
*/

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
