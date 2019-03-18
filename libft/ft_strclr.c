/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:44:50 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/18 12:00:30 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Sets every character of the string to the value of '\0'
*/

/*
** PSEUDOCODE
** If string is not NULL, then use ft_memset to set '\0' with len of string.
*/

#include "libft.h"

void	ft_strclr(char *s)
{
	if (s)
		ft_memset(s, '\0', ft_strlen(s));
}
