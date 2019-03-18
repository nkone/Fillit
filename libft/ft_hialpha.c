/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hialpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:35:13 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/16 15:21:21 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Checks for upper-case
** RETURN VALUES
** 1 for true, 0 otherwise
*/

#include "libft.h"

int	ft_hialpha(int c)
{
	int n;

	n = (c >= 65 && c <= 90) ? 1 : 0;
	return (n);
}
