/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:26:06 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/24 13:05:38 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Allocate (with malloc(3)) and returns a “fresh” string end- ing with ’\0’
** representing the integer n given as argument.
** Negative numbers must be supported.
** If the allocation fails, the function returns NULL.
** RETURN VALUES
** The string representing the integer passed as argument.
*/

/*
** PSEUDOCODE
** Initialize pointer, index, len
** Handle base case for min int
** Find len of int
** Malloc pointer with len of int using ft_strnew()
** Protect malloc return
** Null terminate last index of pointer
** If n is negative, first index is '-'
** While dividing n by 10, set last index to n % 10 + '0'
** Return pointer
*/

#include "libft.h"

static int	int_len(int n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		len;
	int		n_copy;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = (n < 0) ? 1 : 0;
	len = int_len(n);
	if (!(str = ft_strnew(len + sign)))
		return (0);
	str[len] = '\0';
	n_copy = (n < 0) ? -n : n;
	len = (n < 0) ? len + 1 : len;
	while (--len >= 0)
	{
		str[len] = n_copy % 10 + '0';
		n_copy /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
