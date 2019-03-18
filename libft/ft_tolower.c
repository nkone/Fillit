/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:39:54 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/16 11:45:21 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Converts upper-case to lower-case
** RETURN VALUES
** Returns corresponding lower-case if exist, otherwise remains same.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (ft_hialpha(c))
		c += 32;
	return (c);
}
