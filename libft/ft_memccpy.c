/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 08:12:11 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/16 13:17:33 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The memccpy() function copies bytes from string src to string dst.
** If the character c (as converted to an unsigned char) occurs in the str src,
** the copy stops and a pointer to the byte after the copy of c in the
** str dst is returned.
** Otherwise, n bytes are copied, and a NULL pointer is returned.
**
** The src and dst strings should not overlap, as the behavior is undefined.
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;

	dest = dst;
	source = src;
	while (n--)
	{
		if ((*dest++ = *source++) == (unsigned char)c)
			return (dest);
	}
	return (NULL);
}
