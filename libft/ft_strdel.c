/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:36:57 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/18 10:42:21 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Takes as a parameter the address of a string that needs to be freed
** with free(), the set its pointer to NULL.
** RETURN VALUES
** none
*/

/*
** PSEUDOCODE
** If as is not NULL, then free address.
*/

#include "libft.h"

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = 0;
	}
}
