/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 09:48:36 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/18 10:15:57 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Takes as a parameter the address of a memory area that needs to be freed
** with free(), the puts the pointer to NULL.
*/

/*
** PSEUDOCODE
** Checks if address is NULL, if so do nothing.
** Free address pointer with free then set it to NULL
*/

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (!ap)
		return ;
	free(*ap);
	*ap = NULL;
}
