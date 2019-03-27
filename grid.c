/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:01:54 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/27 14:16:38 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*gen_line(int col)
{
	char	*line;
	int		i;

	i = 0;
	if (!(line = (char *)malloc(sizeof(char) * col + 1)))
		return (NULL);
	while (i < col)
	{
		line[i] = '.';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	**gen_grid(int size)
{
	char	**grid;
	int		i;

	i = 0;
	if(!(grid = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (i < size)
	{
		grid[i] = (char *)malloc(sizeof(char) * size + 1);
		free(grid[i]);
		grid[i] = ft_strcpy(grid[i], gen_line(size));
		i++;
	}
	grid[i] = NULL;
	return (grid);
}
int piece_collide(char **grid, int *piece)
{
	int size;
	int i;

	i = 0;
	size = 4;
	while (size--)
	{
		printf("grid[%d, %d]: %c\n", piece[i+1], piece[i], grid[piece[i+1]][piece[i]]);
		if (grid[piece[i+1]][piece[i]] != '.')
			return (1);
		i+=2;
	}
	return (0);
}
int		hi_y(int *tab)
{
	int size;
	int i;
	int y;

	i = 1;
	size = 4;
	y = tab[i];
	while(size--)
	{
		i+=2;
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
	size = 4;
	x = tab[i];
	while(size--)
	{
		i+=2;
		if (x < tab[i])
			x = tab[i];
	}
	return (x);
}

void	insert_piece(char **grid, int *tab, int *x, int *y)
{
	int i;
	char c;
	static int pos;

	c = 'A' + pos;
	i = 0;
	while (i < 8)
	{
		*y = tab[i + 1];
		*x = tab[i];
		grid[*y][*x] = c;
		i += 2;
	}
	pos += 1;
}

int	find_dot(char **grid, int x, int *y, int size)
{
	while (grid[*y][x] && *y < size)
	{
		if (grid[*y][x] == '.')
			break;
		*y += 1;
	}
	if (*y == size - 1)
		return (0);
	return (1);
}

int	box_collide(int *tet, int size)
{
	int x;
	int y;

	x = hi_x(tet);
	y = hi_y(tet);

	if (x >= size || y >= size)
		return (1);
	return (0);
}

void	wipe_grid(char **grid, int size)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] != '.')
				grid[y][x] = '.';
			x++;
		}
		y++;
	}
}

int		*convert_id(char *id)
{
	int *tet;

	(ft_strcmp(id, "I_PIECE") == 0) && (tet = I_PIECE);
	(ft_strcmp(id, "IH_PIECE") == 0) && (tet = IH_PIECE);
	(ft_strcmp(id, "O_PIECE") == 0) && (tet = O_PIECE);
	(ft_strcmp(id, "L_PIECE") == 0) && (tet = L_PIECE);
	(ft_strcmp(id, "LR_PIECE") == 0) && (tet = LR_PIECE);
	(ft_strcmp(id, "LD_PIECE") == 0) && (tet = LD_PIECE);
	(ft_strcmp(id, "LL_PIECE") == 0) && (tet = LL_PIECE);
	(ft_strcmp(id, "J_PIECE") == 0) && (tet = J_PIECE);
	(ft_strcmp(id, "JR_PIECE") == 0) && (tet = JR_PIECE);
	(ft_strcmp(id, "JD_PIECE") == 0) && (tet = JD_PIECE);
	(ft_strcmp(id, "JL_PIECE") == 0) && (tet = JL_PIECE);
	(ft_strcmp(id, "T_PIECE") == 0) && (tet = T_PIECE);
	(ft_strcmp(id, "TR_PIECE") == 0) && (tet = TR_PIECE);
	(ft_strcmp(id, "TD_PIECE") == 0) && (tet = TD_PIECE);
	(ft_strcmp(id, "TL_PIECE") == 0) && (tet = TL_PIECE);
	(ft_strcmp(id, "S_PIECE") == 0) && (tet = S_PIECE);
	(ft_strcmp(id, "SR_PIECE") == 0) && (tet = SR_PIECE);
	(ft_strcmp(id, "Z_PIECE") == 0) && (tet = Z_PIECE);
	(ft_strcmp(id, "ZR_PIECE") == 0) && (tet = ZR_PIECE);

	return (tet);
}
char	**fill_grid()
{
	char **grid = gen_grid(5);
	int	*tab = I_PIECE;
	int x = 0;
	int y = 0;

	insert_piece(grid, I_PIECE, &x, &y);
	if (!(find_dot(grid, x, &y, 5)))
		y = 0;
	x = 1;
	tab = x_shift(O_PIECE, x);
	insert_piece(grid, tab, &x, &y);
	y = 0;
	x = 2;
	tab = x_shift(I_PIECE, x);
	x = 3;
	tab = x_shift(O_PIECE, x);
	insert_piece(grid, tab, &x, &y);
	return(grid);
}

int main(void)
{
	char **grid = fill_grid();
	int i = 0;
	//wipe_grid(grid, 5);

	while(grid[i])
	{
		printf("line %d: |%s|\n", i, grid[i]);
		i++;
	}
}
