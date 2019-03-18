/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:15:23 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/21 20:38:04 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Applies the function f to each character of the string passed as argument.
** Each character is passed by address to f to be modified if necessary.
** RETURN VALUES
** None.
*/

/*
** PSEUDOCODE
** Initialize index i
** If string and address f is not NULL, while string is not NULL,
** Apply f to each character of s.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
		while (*s)
			f(s++);
}
