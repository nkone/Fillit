/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:04:13 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/18 16:08:12 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int main(void)
{
	int fd;

	fd = open("./tetris.txt", O_RDONLY);
	pre_read(fd);
}