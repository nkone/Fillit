/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 09:41:41 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/25 10:34:06 by phtruong         ###   ########.fr       */
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

	y = 4;
	tab = (int *)malloc(sizeof(int) * 8);
	i = 0;
	while (--y >= 0)
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

char	*get_tetid(int *tet)
{
	char *name;

	name = NULL;
	(tabcmp(tet, I_PIECE, sizeof(tet))) && (name = "I_PIECE");
	(tabcmp(tet, IH_PIECE, sizeof(tet))) && (name = "IH_PIECE");
	(tabcmp(tet, O_PIECE, sizeof(tet))) && (name = "O_PIECE");
	(tabcmp(tet, L_PIECE, sizeof(tet))) && (name = "L_PIECE");
	(tabcmp(tet, LR_PIECE, sizeof(tet))) && (name = "LR_PIECE");
	(tabcmp(tet, LD_PIECE, sizeof(tet))) && (name = "LD_PIECE");
	(tabcmp(tet, LL_PIECE, sizeof(tet))) && (name = "LL_PIECE");
	(tabcmp(tet, J_PIECE, sizeof(tet))) && (name = "J_PIECE");
	(tabcmp(tet, JR_PIECE, sizeof(tet))) && (name = "JR_PIECE");
	(tabcmp(tet, T_PIECE, sizeof(tet))) && (name = "T_PIECE");
	(tabcmp(tet, TR_PIECE, sizeof(tet))) && (name = "TR_PIECE");
	(tabcmp(tet, TD_PIECE, sizeof(tet))) && (name = "TD_PIECE");
	(tabcmp(tet, TL_PIECE, sizeof(tet))) && (name = "TL_PIECE");
	(tabcmp(tet, S_PIECE, sizeof(tet))) && (name = "S_PIECE");
	(tabcmp(tet, SR_PIECE, sizeof(tet))) && (name = "SR_PIECE");
	(tabcmp(tet, Z_PIECE, sizeof(tet))) && (name = "Z_PIECE");
	(tabcmp(tet, ZR_PIECE, sizeof(tet))) && (name = "ZR_PIECE");
	return (name);
}
