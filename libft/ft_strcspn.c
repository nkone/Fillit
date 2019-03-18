/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:32:26 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/21 14:33:39 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Spans the initial part of the null-terminated string s as long as the
** characters from s DO NOT occur in the null-terminated string charset.
** Computes the string of the string array index of the first character of s
** which is also in charset, else the index of the first null character.
** RETURN VALUES
** Returns the number of characters spanned.
*/

/*
** PSEUDOCODE
** Initialize counter size_t
** Use ft_strchr() to find matching character from s and charset
** While ft_strchr() is not found, increase counter by one
** Increment pointer from s
** Return count after going through s
*/

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *charset)
{
	size_t	count;

	count = 0;
	while (ft_strchr(charset, *s++) == 0)
		count++;
	return (count);
}
