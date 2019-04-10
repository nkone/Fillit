/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:06:50 by phtruong          #+#    #+#             */
/*   Updated: 2019/04/09 19:46:08 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_tet(stck_tet *stack)
{
	int			c;
	stck_tet	*tmp;

	tmp = stack;
	c = 0;
	while (tmp)
	{
		c++;
		tmp = tmp->next;
	}
	return (c);
}

stck_tet	*id_to_coord(stck_tet *stack)
{
	stck_tet	*head;
	stck_tet	*piece;
	char		*tet_id;
	char		c;
	//int			*tab;

	c = 'A';
	head = NULL;
	while (stack)
	{
		tet_id = stack->tet_id;
		//tab = convert_id(tet_id);
		if (head == NULL)
			head = add_piece(convert_id(tet_id), c++);
		else
			piece = append(convert_id(tet_id), head, c++);
		stack = stack->next;
	}
	return (head);
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
		if (!(tet_id = get_tetid(tet)))
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
