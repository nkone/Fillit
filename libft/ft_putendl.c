/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:12:50 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/20 13:16:08 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Outputs the string s to the standard output followed by a '\n'.
*/

#include "libft.h"

void	ft_putendl(char const *s)
{
	if (!s)
		return ;
	ft_putendl_fd(s, 1);
}
