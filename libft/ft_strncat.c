/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:41:43 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/14 21:18:42 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** strncat() appends a copy of null-terminated str s2 to the end of str s1
** then add terminating '\0'. s1 must have sufficient space.
** RETURN VALUES
** strncat() returns the pointer s1.
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*result;

	result = s1;
	while (*s1)
		s1++;
	while (n--)
	{
		if (!(*s1++ = *s2++))
			return (result);
	}
	*s1 = '\0';
	return (result);
}
