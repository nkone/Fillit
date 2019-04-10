/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:01:54 by phtruong          #+#    #+#             */
/*   Updated: 2019/04/09 19:53:22 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
 
int		start_size(stck_tet *stack)
{
	int blocks;
	int size;

	size = 2;
	blocks = (count_tet(stack) * 4);
	while (blocks > (size * size))
		size += 1;
	return (size);
}

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
	char *line;

	i = 0;
	if(!(grid = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (i < size)
	{
		grid[i] = (char *)malloc(sizeof(char) * size + 1);
		line = gen_line(size);
		ft_strcpy(grid[i], line);
		free(line);
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
	size = 3;
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
	size = 3;
	x = tab[i];
	while(size--)
	{
		i+=2;
		if (x < tab[i])
			x = tab[i];
	}
	return (x);
}

void	insert_piece(char **grid, int *tab, char c)
{
	int i;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 0;
	while (i < 8)
	{
		y = tab[i + 1];
		x = tab[i];
		grid[y][x] = c;
		i += 2;
	}
}
void	clear_piece(char **grid, int *tab)
{
	int i;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 0;
	while (i < 8)
	{
		y = tab[i+1];
		x = tab[i];
		grid[y][x] = '.';
		i+=2;
	}
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

int 	dup_coord(int *dst, int *src)
{
	int *pdst;
	int i = 0;

	pdst = dst;
	while (i < 8)
	{
		pdst[i] = src[i];
		i++;
	}
	return 1;
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

void	stck_free(stck_tet *stack)
{
	stck_tet *tmp;

	tmp = NULL;
	while(stack)
	{
		tmp = stack;
		stack = tmp->next;
		free(tmp);
	}
}

void	stck_free_coord(stck_tet *stack)
{
	stck_tet *tmp;

	tmp = NULL;
	while(stack)
	{
		tmp = stack;
		stack = tmp->next;
		free(tmp->tet_id);
		free(tmp);
	}
}

void	free_grid(char **grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&grid[i]);
		i++;
	}
	free(grid);
}

int		collision(char **grid, int *tet, int size)
{
	return(!(box_collide(tet, size)) && !(piece_collide(grid, tet)));
}

int		help_solve(char **grid,int *tet,stck_tet *stack, int size)
{
	if (collision(grid, tet, size))
	{
		insert_piece(grid, tet, stack->c);
		if (solve_tet(grid, stack->next, size))
		{
			free(tet);
			return (1);
		}
		clear_piece(grid, tet);
	}
	return(0);
}

int solve_tet(char **grid, stck_tet *stack, int size)
{
	int *tet;
	int x;
	int y;

	y = -1;
	tet = (int *)malloc(sizeof(int)*8);
	if (!stack)
	{
		free(tet);
		return (1);
	}
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			dup_coord(tet, stack->tet_id);
			shift_tet(tet, x, y);
			if (help_solve(grid, tet, stack, size))
				return 1;
		}
	}
	free(tet);
	return (0);
}
