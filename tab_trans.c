/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:47:56 by phtruong          #+#    #+#             */
/*   Updated: 2019/04/08 18:01:24 by phtruong         ###   ########.fr       */
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

int		*shift_tet(int *tab, int x, int y)
{
	tab = x_shift(tab, x);
	tab = y_shift(tab, y);

	return (tab);
}
