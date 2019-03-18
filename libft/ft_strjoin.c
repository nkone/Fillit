/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:33:48 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/25 08:51:05 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Allocates w/ malloc() and returns a fresh string ending with '\0',
** result of the concatenation of s1 and s2. If allocation fails, return NULL.
** RETURN VALUES
** The fresh string result of concatenation of 2 strings.
*/

/*
** PSEUDOCODE
** Initialize pointer
** Check if s1 and s2 for NULL
** Set pointer to new string with len of s1 and s2;
** Protect malloc return
** Copy s1 to pointer
** Append s2 to pointer with ft_strcat
** Copy over to pointer
** Return pointer.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;

	if (!s1 || !s2)
		return (NULL);
	str_join = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!str_join)
		return (NULL);
	ft_strcpy(str_join, s1);
	ft_strcat(str_join, s2);
	return (str_join);
}
