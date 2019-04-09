/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:01:54 by phtruong          #+#    #+#             */
/*   Updated: 2019/04/08 17:46:09 by phtruong         ###   ########.fr       */
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
		//printf("grid[%d, %d]: %c\n", piece[i+1], piece[i], grid[piece[i+1]][piece[i]]);
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

void	insert_piece(char **grid, int *tab, int *x, int *y, int flag)
{
	int i;
	int ox;
	int oy;
	char c;
	static int pos;

	ox = *x;
	oy = *y;
	if (flag)
		pos = 0;
	c = 'A' + pos;
	i = 0;
	while (i < 8)
	{
		*y = tab[i + 1];
		*x = tab[i];
		grid[*y][*x] = c;
		i += 2;
	}
	*x = ox;
	*y = oy;
	pos += 1;
}

int	find_dot(char **grid, int x, int *y, int size)
{
	while (*y < size && grid[*y][x])
	{
		if (grid[*y][x] == '.')
			break;
		*y += 1;
	}
	if (*y == size)
		return (0);
	return (1);
}

int	box_collide(int *tet, int size)
{
	int x;
	int y;

	x = hi_x(tet);
	y = hi_y(tet);
	//printf("hi x: %d hi y: %d\n", x, y);
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
int		*dup_coord(int *tet)
{
	int *dup;
	int i = 0;
	dup = (int *)malloc(sizeof(int) * 8);

	while (i < 8)
	{
		dup[i] = tet[i];
		i++;
	}
	return(dup);
}
int		*convert_id(char *id)
{

	//int i = 0;
	int *tet;
	tet = NULL;
	(ft_strcmp(id, "I_PIECE") == 0) && (tet = dup_coord(I_PIECE));
	(ft_strcmp(id, "IH_PIECE") == 0) && (tet = dup_coord(IH_PIECE));
	(ft_strcmp(id, "O_PIECE") == 0) && (tet = dup_coord(O_PIECE));
	(ft_strcmp(id, "L_PIECE") == 0) && (tet = dup_coord(L_PIECE));
	(ft_strcmp(id, "LR_PIECE") == 0) && (tet = dup_coord(LR_PIECE));
	(ft_strcmp(id, "LD_PIECE") == 0) && (tet = dup_coord(LD_PIECE));
	(ft_strcmp(id, "LL_PIECE") == 0) && (tet = dup_coord(LL_PIECE));
	(ft_strcmp(id, "J_PIECE") == 0) && (tet = dup_coord(J_PIECE));
	(ft_strcmp(id, "JR_PIECE") == 0) && (tet = dup_coord(JR_PIECE));
	(ft_strcmp(id, "JD_PIECE") == 0) && (tet = dup_coord(JD_PIECE));
	(ft_strcmp(id, "JL_PIECE") == 0) && (tet = dup_coord(JL_PIECE));
	(ft_strcmp(id, "T_PIECE") == 0) && (tet = dup_coord(T_PIECE));
	(ft_strcmp(id, "TR_PIECE") == 0) && (tet = dup_coord(TR_PIECE));
	(ft_strcmp(id, "TD_PIECE") == 0) && (tet = dup_coord(TD_PIECE));
	(ft_strcmp(id, "TL_PIECE") == 0) && (tet = dup_coord(TL_PIECE));
	(ft_strcmp(id, "S_PIECE") == 0) && (tet = dup_coord(S_PIECE));
	(ft_strcmp(id, "SR_PIECE") == 0) && (tet = dup_coord(SR_PIECE));
	(ft_strcmp(id, "Z_PIECE") == 0) && (tet = dup_coord(Z_PIECE));
	(ft_strcmp(id, "ZR_PIECE") == 0) && (tet = dup_coord(ZR_PIECE));
/*	printf("\nconverted: ");
	while(i < 8)
	{
		printf("%d ", tet[i]);
		i++;
	}*/
	return (tet);
}

stck_tet	*id_to_coord(stck_tet *stack)
{
	stck_tet	*head;
	stck_tet	*piece;
	int			*tab;
	int			i = 0;
	char		*tet_id;
	int			count;

	head = NULL;
	while(stack)
	{
	tet_id = stack->tet_id;
	tab = convert_id(tet_id);
	//printf("tab[0]: %d\n", tab[0]);
	//printf("%s\n", tet_id);
	if (head == NULL)
		head = add_piece(tab);
	else
		piece = append(tab, head);
//	free(tab);
	stack = stack->next;
	}
	return(head);
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

int solve_tet(int x, int y, stck_tet *stack, int size, int flag)
{
	stck_tet *tmp;
	int *tet;

	tmp = stack;
	tet = dup_coord(tmp->tet_id);
	if (!box_collide(tet, size))
	{
		insert_piece(grid, tet, &x, &y, flag);
		free(tet);
	}
	else
		return (0);
	stack = stack->next;
	tmp = stack;
	
	return (0);
}
int main(void)
{
	char **grid;
	int i = 0;
	int fd;
	int size;
	stck_tet *stack;
	stck_tet *tmp;
	stck_tet *store;
	char *tet_id = NULL;
	int *tab = NULL;
	int x, y, flag = 0;
	
	fd = open("tetris.txt", O_RDONLY);
	tmp = store_tet(fd, NULL);
	size = start_size(tmp);
	printf("size: %d\n", size);
	stack = id_to_coord(tmp);
	stck_free(tmp);
	tmp = stack;
	tab = dup_coord(tmp->tet_id);
	while(i < 8)
	{
		printf("tab[%d] : %d\n", i , tab[i]);
		i++;
	}
	x = 0; y =0;
	grid = gen_grid(size);
	insert_piece(grid, tab, &x, &y, flag);
	i = 0;
	while(grid[i])
	{
		printf("line %d: |%s|\n", i, grid[i]);
		i++;
	}
	close(fd);
	while(1){}
}
