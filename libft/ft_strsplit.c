/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 09:57:51 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/04 08:16:23 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Allocates with malloc() and returns an array of "fresh" strings
** (all ending with '\0', including the array itself) obtained by splitting
** s using the character c as a delimiter. If the allocation fails,
** the function returns NULL. Example:
** ft_strplit("*hello*fellow***students*", '*') returns
** ["hello", "fellow", "students"]
** RETURN VALUES
** Array of "fresh" strings result from the split.
*/

/*
** PSEUDOCODE
** Initialize pointer array, a pointer to copy s, token, two counters
** Protect function by checking s for NULL
** Count tokens in s with helper function ft_strtok_ntokens()
** Allocate memory before copy s;
** Copy array pointer and protect return
** Copy s to pointer
** Get first token with ft_strtok_r
** While index is less than no. of tokens and token is not NULL
** |--> Allocate memory into index array with size of token
** |--> Copy token into that index
** |--> Get new token with ft_strtok_r
** |--> Increment index
** NULL terminate last index
** Return pointer array
*/

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**s_array;
	char	*s_copy;
	int		w_count;
	char	*token;
	int		i;

	if (!s)
		return (NULL);
	w_count = ft_strtok_ntokens(s, &c);
	s_copy = (char *)malloc(ft_strlen(s) * sizeof(char));
	if (!(s_array = (char **)malloc(w_count * sizeof(char *) + 1)))
		return (NULL);
	ft_strcpy(s_copy, s);
	token = ft_strtok_r(s_copy, &c, &s_copy);
	i = 0;
	while (i < w_count && token != NULL)
	{
		s_array[i] = (char *)malloc(ft_strlen(token) * sizeof(char));
		ft_strcpy(s_array[i], token);
		token = ft_strtok_r(s_copy, &c, &s_copy);
		i++;
	}
	s_array[i] = NULL;
	return (s_array);
}
