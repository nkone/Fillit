/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_nchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:31:51 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/24 12:52:46 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Uses strchr() to find the no. of delimiters c (convert to char) in a str
** RETURN VALUES
** No. of delimiters
*/

#include "libft.h"

int	ft_strchr_nchr(char const *str, int c)
{
	int		count;
	char	*pstr;

	if (!*str)
		return (0);
	pstr = (char *)str;
	count = 0;
	while ((pstr = ft_strchr(pstr, (char)c)) != NULL)
	{
		count++;
		pstr++;
	}
	return (count);
}
