/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:17:44 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/18 10:35:17 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Allocates (with malloc()) and returns a "fresh" string ending with '\0'.
** Each character of the string is initialized at '\0'.
** If allocation fails, return NULL
** RETURN VALUES
** Allocated string and initialized to 0.
*/

/*
** PSEUDOCODE
** Initialize char pointer.
** Allocate pointer with malloc with length of size + 1;
** If allocation fails, return NULL;
** Set all character to '\0' with ft_bzero(pointer, size + 1);
** Return allocated string.
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str_slot;

	str_slot = (char *)malloc(size + 1);
	if (!str_slot)
		return (NULL);
	else
		ft_bzero(str_slot, size + 1);
	return (str_slot);
}
