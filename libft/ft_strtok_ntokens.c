/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_ntokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:02:09 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/23 20:03:56 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Get number of tokens with delimiter of char const *c w/o modifying original
** str, using ft_strtok(); free the copied string.
** RETURN VALUES
** No. of tokens found in str after separating limiters.
*/

#include "libft.h"

int	ft_strtok_ntokens(char const *str, char const *c)
{
	char	*str_cpy;
	size_t	len;
	size_t	count;

	count = 0;
	len = ft_strlen(str);
	if (!(str_cpy = ft_strnew(len + 1)))
		return (0);
	ft_strcpy(str_cpy, str);
	if (ft_strtok(str_cpy, c) != NULL)
	{
		count++;
		while (ft_strtok(NULL, c) != NULL)
			count++;
	}
	free(str_cpy);
	return (count);
}
