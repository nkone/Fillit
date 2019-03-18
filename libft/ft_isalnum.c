/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 10:32:46 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/16 15:21:55 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Checks if isalpha or isnum true
** RETURN VALUES
** 1 for true, 0 for false.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	int n;

	n = (ft_isalpha(c) || ft_isdigit(c)) ? 1 : 0;
	return (n);
}
