/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:56:06 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/21 20:37:45 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Applies function f to each of the char of string, and passing its index
** as first argument. Each character is modifed by address of f
** RETURN VALUES
** None.
*/

/*
** PSEUDOCODE
** Initialize index
** If str and f is not NULL, while str is not NULL,
** Apply function f with index.
** Increase index by one.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s && f)
		while (*s)
			f(i++, s++);
}
