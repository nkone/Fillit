/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:47:56 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/26 17:53:06 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*x_shift(int *tab, int x)
{
	int i;
	int size;

	size = 4;
	i = 0;
	while (size--)
	{
		tab[i] = tab[i] + x;
		i+=2;
	}
	return(tab);
}

int		*y_shift(int *tab, int y)
{
	int i;
	int size;

	size = 4;
	i = 1;
	while (size--)
	{
		tab[i] = tab[i] + y;
		i+=2;
	}
	return(tab);
}
