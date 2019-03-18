/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:16:36 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/13 11:02:10 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The memcpy() function copies n bytes from mem src to mem dst.
** If dst and src overlap, behavior is undefined.
** When dst, src overlap, use memmove() instead.
** RETURN VALUES
** The memcpy() function returns the original value of dst.
** Examples: ft_memcpy(str1, str2, strlen(str2))
** copies contents of str2 w/ len of str2 to str1 and replace.
** str1: "Replace with Test" || str2: "Test"
** After memcpy, str1: "Test".
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*source;

	dest = dst;
	source = src;
	while (n--)
		*dest++ = *source++;
	return (dst);
}
