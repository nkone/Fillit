/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 09:41:41 by phtruong          #+#    #+#             */
/*   Updated: 2019/04/10 09:49:50 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		low_x(int *tab)
{
	int x;
	int i;
	int size;

	size = 4;
	i = 0;
	x = tab[i];
	while (size--)
	{
		if (tab[i] >= 0 && tab[i] <= 3)
			if (tab[i] < x)
				x = tab[i];
		i += 2;
	}
	return (x);
}

int		low_y(int *tab)
{
	int y;
	int i;
	int size;

	size = 4;
	i = 1;
	y = tab[i];
	while (size--)
	{
		if (tab[i] >= 0 && tab[i] <= 3)
			if (tab[i] < y)
				y = tab[i];
		i += 2;
	}
	return (y);
}

int		*one_tetris(const int fd, char *line)
{
	int		x;
	int		y;
	int		*tab;
	int		i;

	y = -1;
	tab = (int *)malloc(sizeof(int) * 8);
	i = 0;
	while (++y <= 3)
	{
		x = 0;
		get_next_line(fd, &line);
		while (line[x])
		{
			if (line[x] == '#')
			{
				tab[i] = x;
				tab[i + 1] = y;
				i += 2;
			}
			x++;
		}
		free(line);
	}
	return (tab);
}

int		*trans_coord(int *tab)
{
	int lx;
	int ly;
	int i;
	int size;

	size = 4;
	lx = low_x(tab);
	ly = low_y(tab);
	i = 0;
	while (size--)
	{
		tab[i] -= lx;
		tab[i + 1] -= ly;
		i += 2;
	}
	return (tab);
}

int		dup_coord(int *dst, int *src)
{
	int *pdst;
	int i;

	i = 0;
	pdst = dst;
	while (i < 8)
	{
		pdst[i] = src[i];
		i++;
	}
	return (1);
}
