/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 20:34:48 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/15 21:16:46 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** strncpy() compares not more than n characters. Characters after '\0'
** are not compared.
** RETURN VALUES
** strncmp() return an integer greater than, equal to, or less than 0,
** according as the string s1 is greater than, equal to, or less than string 2.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*s1 != *s2++)
			return (*(unsigned char*)s1 - *(unsigned char *)(s2 - 1));
		if (*s1++ == 0)
			break ;
	}
	return (0);
}
