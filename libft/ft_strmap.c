/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:29:14 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/21 20:38:43 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Applies function f to each character of string given to create a "fresh"
** new string with malloc() resulting from successive applications of f.
** RETURN VALUES
** The "fresh" string created from successive applications of f.
*/

/*
** PSEUDOCODE
** Initilize a pointer and index;
** If string is NULL, return NULL;
** Set pointer to a new string with ft_strnew(len of s)
** If pointer is NULL, return NULL;
** Apply function f while s is not NULL, set pointer equal to f(s);
** Iterates with increment ++;
** '\0' terminate pointer;
** Return pointer;
*/

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ps;
	int		i;

	ps = (char *)s;
	if (!s)
		return (NULL);
	ps = ft_strnew(ft_strlen(s));
	if (!ps)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ps[i] = f(s[i]);
		i++;
	}
	ps[i] = '\0';
	return (ps);
}
