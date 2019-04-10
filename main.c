/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:07:16 by phtruong          #+#    #+#             */
/*   Updated: 2019/04/09 20:17:30 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

void	print_grid(char **grid, int size)
{
	int	i;

	i = -1;
	while (grid[++i])
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
	}
	free_grid(grid, size);
}

int		solve_driver(int fd)
{
	stck_tet	*tmp;
	stck_tet	*stack;
	int			size;
	char		**grid;

	tmp = store_tet(fd, NULL);
	size = start_size(tmp);
	stack = id_to_coord(tmp);
	stck_free(tmp);
	grid = gen_grid(size);
	while (!solve_tet(grid, stack, size))
	{
		free_grid(grid, size);
		size += 1;
		grid = gen_grid(size);
	}
	print_grid(grid, size);
	stck_free_coord(stack);
	return (1);
}

int		main(int argc, char *argv[])
{
	int	fd;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr(USAGE);
		exit(1);
	}
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit();
	else if (fd > 0)
	{
		if (pre_read(fd))
		{
			fd = open(argv[1], O_RDONLY);
			solve_driver(fd);
		}
	}
	close(fd);
}
