/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:15:33 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/22 10:53:51 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Isolate sequential tokens in a null-terminated string, str.
** These tokens are separeted in the string by at least one of the character
** in sep. The first time that strtok() is called, str should be specified;
** subsequent calls, wishing to obtain more tokens from the same string,
** should pass a null pointer instead. The separator string, sep, must be
** supplied each time, and may change between calls.
*/

/*
** PSEUDOCODE
** Initialize static char pointer
** If str is not NULL, pointer --> str
** Else return NULL
** Look for separate character(s) in pointer and move str position there.
** |--> str = pstr + ft_strspn(pstr, sep);
** Look for anything, NOT separate character(s) in str, move pointer there.
** |--> p = str + ft_strcspn(str, sep);
** If both pointer and str position is same, null terminate position.
** If pointer is not NULL
** |--> Set current to NULL
** |--> Increment pointer to next position.
** Else set pointer to NULL;
*/

#include "libft.h"

char	*ft_strtok(char *str, const char *sep)
{
	static char *p = 0;

	if (str)
		p = str;
	else if (!p)
		return (0);
	str = p + ft_strspn(p, sep);
	p = str + ft_strcspn(str, sep);
	if (p == str)
		return (p = 0);
	if (*p)
	{
		*p = 0;
		p += 1;
	}
	else
		p = 0;
	return (str);
}
