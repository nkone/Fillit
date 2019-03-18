/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:16:30 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/15 13:18:27 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The strdup() function allocates sufficient memory for a copy of
** the string s1, does the copy, and returns a pointer to it.
** The pointer may subsequently be used as an argument to the function
** free(3).
**
** If insufficient memory is available, NULL is returned
** and errno is set to ENOMEM.
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	n;
	char	*result;

	n = ft_strlen(s1) + 1;
	result = (char *)malloc(n);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, n);
	return (result);
}
