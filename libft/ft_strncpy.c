/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:42:25 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/14 10:47:46 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** the strncpy() copies at most len characters from src into dst. If src
** is less than len characters long, the remainder of dst is filled with '\0'.
** Otherwise, dst is not terminated.
** src and dst should not overlap, as the behavior is undefined.
** RETURN VALUES
** strncpy() returns dst.
*/

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*dest;
	size_t	n;

	dest = dst;
	n = 0;
	while (n < len && src[n] != '\0')
	{
		dst[n] = src[n];
		n++;
	}
	while (n < len)
		dst[n++] = '\0';
	return (dst);
}
