/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:39:18 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/22 13:43:49 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	DESCRIPTION
**	The memset() function writes len bytes of value c (converted to an
** 	unsigned char) to the string b.
**
**	RETURN VALUES
**	The memset() function returns its first argument.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *dest;

	dest = (unsigned char *)b;
	if (len)
		while (len--)
			*dest++ = c;
	return (b);
}
