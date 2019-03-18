/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:31:24 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/16 15:23:54 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Check if character is lower-case.
** RETURN VALUES
** Non-zero for true, 0 otherwise.
*/

#include "libft.h"

int	ft_loalpha(int c)
{
	int n;

	n = (c >= 97 && c <= 122) ? 1 : 0;
	return (n);
}
