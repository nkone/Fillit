/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:18:27 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/25 14:44:16 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** strspn() computes the length of the maximum initial segment of string
** pointed to by s1 which consists entirely of characters from the string
** pointed to by s2.
** RETURN VALUES
** length of the segment
*/

/*
** PSEUDOCDOE
** Initialize size_t counter
** While s1 is true and ft_strchr(s2, *s1++)
** |--> increment counter
** Return counter
** ft_strchr(s2, *s1++) checks thru s1  if there is character in s1 in s2
*/

#include "libft.h"

size_t	ft_strspn(const char *s1, const char *s2)
{
	size_t	counter;

	counter = 0;
	while (*s1 && ft_strchr(s2, *s1++))
		counter++;
	return (counter);
}
