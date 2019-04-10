/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:31:46 by phtruong          #+#    #+#             */
/*   Updated: 2019/04/10 09:38:02 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		hi_y(int *tab)
{
	int size;
	int i;
	int y;

	i = 1;
	size = 3;
	y = tab[i];
	while (size--)
	{
		i += 2;
		if (y < tab[i])
			y = tab[i];
	}
	return (y);
}

int		hi_x(int *tab)
{
	int size;
	int i;
	int x;

	i = 0;
	size = 3;
	x = tab[i];
	while (size--)
	{
		i += 2;
		if (x < tab[i])
			x = tab[i];
	}
	return (x);
}

int		piece_collide(char **grid, int *piece)
{
	int size;
	int i;

	i = 0;
	size = 4;
	while (size--)
	{
		if (grid[piece[i + 1]][piece[i]] != '.')
			return (1);
		i += 2;
	}
	return (0);
}

int		box_collide(int *tet, int size)
{
	int x;
	int y;

	x = hi_x(tet);
	y = hi_y(tet);
	if (x >= size || y >= size)
		return (1);
	return (0);
}

int		collision(char **grid, int *tet, int size)
{
	return (!(box_collide(tet, size)) && !(piece_collide(grid, tet)));
}
