/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:16:52 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/13 14:00:53 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The strlen() function computes the length of the string s.
** The strnlen() function attempts to compute the length of s,
** but never scans beyond the first maxlen bytes of s.
** RETURN VALUES
** The strlen() function returns the number of characters that precede
** the terminating NUL character.
** The strnlen() function returns either the same result as strlen()
** or maxlen, whichever is smaller.
*/

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}
