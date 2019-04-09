/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 12:57:32 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/25 10:23:37 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **one_block(const int fd)
{
	char **block;
	char buff[BLOCK_SIZE + 1];
	int	chr_read;

	block = NULL;
	if (fd > 0)
	{
		chr_read = read(fd, buff, BLOCK_SIZE);
		if (chr_read == 0)
			return (NULL);
		buff[BLOCK_SIZE] = '\0';
		block = ft_strsplit(buff, '\n');
	}
	else
		return (NULL);
	return (block);
}
