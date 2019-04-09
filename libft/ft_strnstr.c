/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:44:18 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/28 10:59:54 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** strnstr() locates the first occurrence of the null-terminated string find
** in the string str, where not more than len characters are searched.
** Characters that appear after a '\0' are not searched.
** RETURN VALUES
** If find is an empty string, str is returned; if find is not found, returns
** NULL; otherwise return pointer to the first character found.
*/

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	str_len;
	size_t	find_len;
	size_t	n;

	str_len = ft_strlen(str);
	find_len = ft_strlen(find);
	n = len - find_len;
	if (n > str_len)
		n = str_len;
	if (!*find)
		return (char *)str;
	if (!find_len)
		return (char *)str;
	if (find_len > len || str_len < find_len)
		return (NULL);
	if (!ft_memcmp(str, find, find_len))
		return (char *)str;
	while (n--)
	{
		if (ft_memcmp(++str, find, find_len) == 0)
			return (char *)str;
	}
	return (NULL);
}
