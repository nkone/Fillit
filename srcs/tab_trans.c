/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:47:56 by phtruong          #+#    #+#             */
/*   Updated: 2019/04/10 09:47:57 by phtruong         ###   ########.fr       */
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
		i += 2;
	}
	return (tab);
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
		i += 2;
	}
	return (tab);
}

int		*shift_tet(int *tab, int x, int y)
{
	tab = x_shift(tab, x);
	tab = y_shift(tab, y);
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
	(tabcmp(tet, JD_PIECE, sizeof(tet))) && (name = "JD_PIECE");
	(tabcmp(tet, JL_PIECE, sizeof(tet))) && (name = "JL_PIECE");
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

int		*convert_id(char *id)
{
	int *tet;

	tet = (int *)malloc(sizeof(int) * 8);
	(ft_strcmp(id, "I_PIECE") == 0) && (dup_coord(tet, I_PIECE));
	(ft_strcmp(id, "IH_PIECE") == 0) && (dup_coord(tet, IH_PIECE));
	(ft_strcmp(id, "O_PIECE") == 0) && (dup_coord(tet, O_PIECE));
	(ft_strcmp(id, "L_PIECE") == 0) && (dup_coord(tet, L_PIECE));
	(ft_strcmp(id, "LR_PIECE") == 0) && (dup_coord(tet, LR_PIECE));
	(ft_strcmp(id, "LD_PIECE") == 0) && (dup_coord(tet, LD_PIECE));
	(ft_strcmp(id, "LL_PIECE") == 0) && (dup_coord(tet, LL_PIECE));
	(ft_strcmp(id, "J_PIECE") == 0) && (dup_coord(tet, J_PIECE));
	(ft_strcmp(id, "JR_PIECE") == 0) && (dup_coord(tet, JR_PIECE));
	(ft_strcmp(id, "JD_PIECE") == 0) && (dup_coord(tet, JD_PIECE));
	(ft_strcmp(id, "JL_PIECE") == 0) && (dup_coord(tet, JL_PIECE));
	(ft_strcmp(id, "T_PIECE") == 0) && (dup_coord(tet, T_PIECE));
	(ft_strcmp(id, "TR_PIECE") == 0) && (dup_coord(tet, TR_PIECE));
	(ft_strcmp(id, "TD_PIECE") == 0) && (dup_coord(tet, TD_PIECE));
	(ft_strcmp(id, "TL_PIECE") == 0) && (dup_coord(tet, TL_PIECE));
	(ft_strcmp(id, "S_PIECE") == 0) && (dup_coord(tet, S_PIECE));
	(ft_strcmp(id, "SR_PIECE") == 0) && (dup_coord(tet, SR_PIECE));
	(ft_strcmp(id, "Z_PIECE") == 0) && (dup_coord(tet, Z_PIECE));
	(ft_strcmp(id, "ZR_PIECE") == 0) && (dup_coord(tet, ZR_PIECE));
	return (tet);
}
