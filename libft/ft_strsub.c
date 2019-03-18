/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:46:40 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/18 20:31:58 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Allocates with malloc() and return a fresh substring from the string
** given as argument. The substring begins at indext start and is size len.
** If start and len aren't refering to a valid substring,
** the behavior is undefined. If the allocation fails, returns NULL.
** RETURN VALUES
** The substring.
*/

/*
** PSEUDOCODE
** Initialize pointer and index;
** Check if s is NULL, if so return NULL
** Set pointer to new fresh allocated string with ft_strnew(size of len);
** Protect malloc return;
** While index is less than len, set pointer index = to s with index start;
** Return pointer;
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ps;
	size_t	i;

	if (!s)
		return (NULL);
	ps = ft_strnew(len);
	if (!ps)
		return (NULL);
	i = 0;
	while (i < len)
		ps[i++] = s[start++];
	return (ps);
}
