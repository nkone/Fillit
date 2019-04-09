/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:30:19 by phtruong          #+#    #+#             */
/*   Updated: 2019/04/08 21:30:32 by phtruong         ###   ########.fr       */
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

int			count_tet(stck_tet *stack)
{
	int c;
	stck_tet *tmp;

	tmp = stack;
	c = 0;
	while(tmp)
	{
		c++;
		tmp = tmp->next;
	}
	return (c);
}

stck_tet	*add_piece(void *tet_id, char tet_c)
{
	stck_tet *piece;

	piece = (stck_tet *)malloc(sizeof(stck_tet));
	piece->tet_id = tet_id;
	piece->c = tet_c;
	piece->next = NULL;
	return (piece);
}

stck_tet	*append(void *tet_id, stck_tet *head, char c)
{
	stck_tet *cursor;
	stck_tet *piece;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	piece = add_piece(tet_id, c);
	cursor->next = piece;
	return (head);
}

stck_tet	*store_tet(const int fd, char *line)
{
	int			*tet;
	char		*tet_id;
	stck_tet	*piece;
	stck_tet	*first;
	char		c;

	c = 'A';
	first = NULL;
	while (1)
	{
		tet = trans_coord(one_tetris(fd, line));
		if(!(tet_id = get_tetid(tet)))
			ft_exit();
		if (first == NULL)
			first = add_piece(tet_id, c++);
		else
			piece = append(tet_id, first, c++);
		free(tet);
		if (!(get_next_line(fd, &line)))
			break ;
		free(line);
	}
	close(fd);
	return (first);
}
