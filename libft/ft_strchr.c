/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:32:51 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/25 14:49:27 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** strchr() locates first occurence of c (converted to a char) in the string
** pointed to by s. Terminating null is considered to be part of the string.
** If c is '\0', then the funtions locate '\0'.
** RETURN VALUES
** strchr() return a pointer to the located character, or NULL if c not found.
*/

/*
** PSEUDOCODE
** While s is not same as character c, move s forward
** If pointer reaches NULL return NULL
** Return pointer s otherwise
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (NULL);
	return (char *)s;
}
