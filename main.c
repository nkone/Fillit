/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:30:19 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/25 10:31:57 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_piece(stck_tet *piece)
{
	while (piece)
	{
		printf("%s\n", piece->tet_id);
		piece = piece->next;
	}
}

stck_tet	*add_piece(char *tet_id)
{
	stck_tet *piece;

	piece = (stck_tet *)malloc(sizeof(stck_tet));
	piece->tet_id = tet_id;
	piece->next = NULL;
	return (piece);
}

stck_tet	*append(char *tet_id, stck_tet *head)
{
	stck_tet *cursor;
	stck_tet *piece;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	piece = add_piece(tet_id);
	cursor->next = piece;
	return (head);
}

stck_tet	*store_tet(int fd, char *line)
{
	int			*tet;
	char		*tet_id;
	stck_tet	*piece;
	stck_tet	*first;

	first = NULL;
	while (1)
	{
		tet = trans_coord(one_tetris(fd, line));
		if(!(tet_id = get_tetid(tet)))
			ft_exit();
		if (first == NULL)
			first = add_piece(tet_id);
		else
			piece = append(tet_id, first);
		free(tet);
		if (!(get_next_line(fd, &line)))
			break ;
		free(line);
	}
	close(fd);
	return (first);
}

int			main(void)
{
	int			fd;
	char *line;
	stck_tet	*stack;
	fd = open("./tetris.txt", O_RDONLY);
	line = NULL;
	//pre_read(fd);
	//fd = open("./tetris.txt", O_RDONLY);
	stack = store_tet(fd, NULL);
	print_piece(stack);
	close(fd);
}
