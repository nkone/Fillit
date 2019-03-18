/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:06:30 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/15 11:13:05 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** strnlen() computes the length of string str but never scans the first
** maxlen of string str.
** RETURN VALUES
** strnlen() returns either same result as strlen() or maxlen,
** whichever is smaller.
*/

#include "libft.h"

size_t	ft_strnlen(const char *str, size_t maxlen)
{
	char *pstr;

	pstr = ft_memchr(str, 0, maxlen);
	if (!pstr)
		return (maxlen);
	else
		return (pstr - str);
}
