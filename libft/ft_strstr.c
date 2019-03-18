/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:15:18 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/15 14:32:20 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** strstr() locates the first occurence of null-terminated string find
** in null-terminated string str.
** RETURN VALUES
** If find is empty, str is returned; if find is not found, NULL is returned.
** Otherwise, pointer to the first character of first occurence of find
** is returned.
*/

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	size_t	str_len;
	size_t	find_len;

	find_len = ft_strlen(find);
	str_len = ft_strlen(str);
	if (!*find)
		return (char *)str;
	str = ft_strchr(str, find[0]);
	if (str == NULL || find[1] == '\0')
		return (char *)str;
	if (str_len < find_len)
		return (NULL);
	if (ft_memcmp(str, find, find_len) == 0)
		return (char *)str;
	while (*str++)
		if (!ft_memcmp(str, find, find_len))
			return (char *)str;
	return (0);
}
