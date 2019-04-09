/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 18:40:40 by phtruong          #+#    #+#             */
/*   Updated: 2019/04/01 13:05:14 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_exit()
{
	printf("error\n");
	exit(1);
}

int	h_count(char *line)
{
	int count;

	count = 0;
	if(!line)
		return (0);
	while(*line)
	{
		if (*line == '#')
			count++;
		line++;
	}
	return (count);
}

int	chk_char(char *line)
{
	while (*line)
	{
		if (*line != '.' && *line != '#')
			return (0);
		line++;
	}
	return (1);
}

int read_one(const int fd, char *line)
{
	int n_line;
	int count;

	n_line = 0;
	count = 0;
	while (n_line < 4)
	{
		get_next_line(fd, &line);
		count += h_count(line);
		if (ft_strlen(line) != 4 || count > 4 || !chk_char(line))
			ft_exit();
		n_line++;
		free(line);
	}
	if (count < 4)
		ft_exit();
	return (1);
}

int pre_read(const int fd)
{
	char *line;

	line = NULL;
	while (1)
	{
		read_one(fd, line);
		if (!get_next_line(fd, &line))
			break;
		free(line);
		if (ft_strlen(line) != 0)
			ft_exit();
	}
	close(fd);
	return(1);
}
