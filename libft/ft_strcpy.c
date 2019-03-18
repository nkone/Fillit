/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:26:14 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/14 11:29:24 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** strcpy() functions copy the string src to dst
** (including the terminating `\0' character.) Does not overrides src.
** RETURN VALUES
** strcpy() returns dst.
*/

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*string;
	size_t	n;

	n = ft_strlen(src) + 1;
	string = ft_memcpy(dst, src, n);
	return (string);
}
