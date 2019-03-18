/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 09:34:18 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/16 15:23:11 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Check for spaces
** RETURN VALUES
** 1 for true, 0 for false
*/

#include "libft.h"

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}
