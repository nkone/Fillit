/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:51:04 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/21 20:39:57 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Applies the function f to each of the string passed as argument by giving
** its index as first argument to create a "fresh" new string with malloc()
** resulting from the successive application of f.
** RETURN VALUES
** The "fresh" string created from successive application of f.
*/

/*
** PSEUDOCODE
** Initialize pointer and index;
** If string is NULL, return NULL;
** Set pointer to a new string with ft_strnew(len of s);
** If pointer is NULL, return NULL; (protect malloc return);
** While s is true, apply f, set pointer = to f(i, s);
** Increment index
** '\0' terminate pointer;
** Return pointer;
*/

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ps;

	i = 0;
	if (!s)
		return (NULL);
	ps = ft_strnew(ft_strlen(s));
	if (!ps)
		return (NULL);
	while (s[i])
	{
		ps[i] = f(i, s[i]);
		i++;
	}
	ps[i] = '\0';
	return (ps);
}
