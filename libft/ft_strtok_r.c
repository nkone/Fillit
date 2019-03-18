/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:46:39 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/24 13:03:12 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Parse s into tokens separated by delim.
** If s is NULL, the saved pointer is used as the next starting point.
** Example:
** char s[] = "-abc-=-def";
** char *ps;
** x = strtok_r(s, "-", &ps); // x = "abc, ps = "=-def"
** x = strtok_r(NULL, "-=", &sp); // x = "def", sp = NULL;
** x = strtok_r(NULL, "=", &sp); // x = NULL;
** // s = "abc\0-def\0"
*/

#include "libft.h"

char	*ft_strtok_r(char *s, char const *delim, char **save_ps)
{
	char	*s_end;

	if (s == NULL)
		s = *save_ps;
	if (!*s)
	{
		*save_ps = s;
		return (NULL);
	}
	s = s + ft_strspn(s, delim);
	if (!*s)
	{
		*save_ps = s;
		return (NULL);
	}
	s_end = s + ft_strcspn(s, delim);
	if (!*s_end)
	{
		*save_ps = s_end;
		return (s);
	}
	*s_end = '\0';
	*save_ps = s_end + 1;
	return (s);
}
