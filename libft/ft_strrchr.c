/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:58:43 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/14 22:44:47 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** strrchr() locates the last occurence of c.
** RETURN VALUES
** strrchr() returns a pointer to the located character, or NULL if not found.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*p_found;

	p = NULL;
	c = (unsigned char)c;
	if (c == '\0')
		return (ft_strchr(s, c));
	p_found = NULL;
	while ((p = ft_strchr(s++, c)) != '\0')
		p_found = p;
	return (p_found);
}
