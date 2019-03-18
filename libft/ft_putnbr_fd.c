/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:20:25 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/24 16:43:09 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Outputs the integer n to the file descriptor fd.
*/

/*
** PSEUDOCODE
** Check for negative cases
** If n = int_min value
** |--> ft_putstr_fd(int_min value)
** If negative,
** |--> output negative symbol, then set n to negative
** If n is between 0 and 9 inclusively,
** |--> output the number.
** If n is 10 and above
** |--> Recall function with n/10
** |--> Recall funciton with n%10
*/
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	ft_putstr_fd(ft_itoa(n), fd);
}
