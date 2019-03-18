/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:23:06 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/21 20:43:42 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Allocates with malloc() and returns a copy of the string given
** as argument without white spaces at beginning and end of string.
** Will be considered as whitespaces, ' ', '\n', and '\t'.
** If s has no whitespaces at the beginning or at the end, the function
** returns a copy of s. If the allocation fails the function returns NULL.
** RETURN VALUES
** The "fresh" trimmed string or copy of s
*/

/*
** PSEUDOCODE
** Initilize variables:
** |--> b_space: beginning spaces; e_space: end space; *str_trim: trimmed str.
** Check s for NULL.
** While there are spaces, move b_space -->
** If b_space reaches end, return empty string.
** Find index for e_space
** While there are spaces, move e_space <--
** Set str_trim to malloc ft_strnew(size of e_space - b_space + 1)
** Protect malloc return
** ft_strncpy() starting from s+b_space and len of (e_space - b_space + 1)
** Return str_trim
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		b_space;
	int		e_space;
	char	*str_trim;

	if (!s)
		return (0);
	b_space = 0;
	while (*s && ft_isspace(s[b_space]))
		b_space++;
	if (!s[b_space])
		return (ft_strnew(0));
	e_space = ft_strlen(s) - 1;
	while (ft_isspace(s[e_space]))
		e_space--;
	str_trim = ft_strnew((e_space - b_space) + 1);
	if (!str_trim)
		return (0);
	ft_strncpy(str_trim, (s + b_space), ((e_space - b_space) + 1));
	return (str_trim);
}
