/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:18:29 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/14 21:42:00 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESTINATION
** strlcat() appends str src to end of dst of size dstsize then NULL terminate.
** dstsize is full size of dst. If return >= dstsize, truncation occurred.
** RETURN VALUES
** strlcat() returns the total length of the str trying to create.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dest;
	const char	*sauce;
	size_t		dest_len;
	size_t		n;

	dest = dst;
	n = dstsize;
	sauce = src;
	while (n-- && *dest)
		dest++;
	dest_len = dest - dst;
	n = dstsize - dest_len;
	if (n == 0)
		return (dest_len + ft_strlen(sauce));
	while (*sauce)
	{
		if (n > 1)
		{
			*dest++ = *sauce;
			n--;
		}
		sauce++;
	}
	*dest = '\0';
	return (dest_len + (sauce - src));
}
