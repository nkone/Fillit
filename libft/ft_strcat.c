/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 10:16:20 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/14 11:25:18 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** strcat() appends a copy of the null-terminated str s2 to the end of str s1
** RETURN VALUES
** strcat() returns the pointer s1.
*/

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t n;

	n = ft_strlen(s1);
	ft_strcpy(s1 + n, s2);
	return (s1);
}
