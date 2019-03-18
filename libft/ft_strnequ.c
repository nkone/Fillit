/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:49:14 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/18 15:54:40 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Lexicographical comparison between s1 and s2 up to n characters
** or ntil '\0' is reached. If 2 strings are identical, return 1, 0 otherwise.
** RETURN VALUES
** 1 if *s1==*s2, 0 otherwise.
*/

/*
** PSEUDOCDE
** Return 1 if ft_strncmp(s1, s2, n) == 0, 0 otherwise
*/

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if (!ft_strncmp(s1, s2, n))
		return (1);
	return (0);
}
