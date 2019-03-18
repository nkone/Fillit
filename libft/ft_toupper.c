/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:27:31 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/16 11:39:15 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Convert lower-case letter to upper-case
** RETURN VALUES
** If there is a lower-case, conver to upper otherwise remain same.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_loalpha(c))
		c -= 32;
	return (c);
}
