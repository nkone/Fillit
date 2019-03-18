/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 09:18:28 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/21 20:35:57 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Allocates (with malloc()) and returns a "fresh" memory area.
** The memory allocated is initilaized to 0.
** If the allocation fails, the function returns NULL.
** RETURN VALUES
** The allocated memory area.
*/

/*
** PSEUDOCODE
** Initilize pointer -> set pointer to malloc w/ length of size.
** If size is 0 then return NULL
** Put zero bytes in allocated memory. Use ft_bzero.
** Return pointer.
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned int	*slot;

	slot = (unsigned int *)malloc(size);
	if (!slot)
		return (NULL);
	ft_bzero(slot, size);
	return (slot);
}
