/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:21:36 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/24 13:32:53 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** This is a function that returns a line read from a file descriptor
*/

/*
** WORK CHECKLIST
** read function returns a non-negative integer indicating no. bytes read
** otherwise -1, indicating error.✓
** Find a way to null-termintate garbages.✓
** Check for FD_LIMIT✓
** Make test for two/ may be three files ✓
** Add fd for token_me function so I can access index directly ✓
** Note to self:
** Token does not work for empty line, since strtok null terminates all delims
** Freeing token is dangerous, ran into multiple errors if not handle correctly
** ex. pointer cannot be free because it's not allocated.
** ft_strclr is does not free.
** char *s = ft_strnew(0) is not same as char *s = "";
** Pointer arithmetic is useful to navigate around strings.
** Since strchr returns a string, similar to pointer arithmetic,
** by adding int value to it, it's possible to copy from that position,
** Useful for bypassing '\0' or any certain characters.
*/

#include "libft.h"

/*
** ret_line()
** Takes in the variables from gnl and return 1 if line exists
** ===========================================================
** Before separating the newline:
** Check for what was read, if the array[fd] is empty, meaning
** nothing is read nor done, return 0.
** Main function description:
** Check if the array[fd] has a newline
** If there is one:
** Set that '\n' to '\0', then point line to a new string, resulting from
** string duplication of the null-terminated array[fd].
** Even if the string is null-terminated, there are 'hidden' left over
** behind the null. Thus, using a temp pointer, point it to a string
** resulting from duplicating everything left over behind that null marker.
** Free array[fd] so it can points a new string, resulting from
** string duplication of temp pointer earlier.
** Free the temp pointer.
** If there is none:
** Simply point line to a new string, resulting from string duplication
** of array[fd]. Then, clear the array after.
*/

int	ret_line(char **tmp, char **line, int fd)
{
	char *tmp_h;

	if (!*tmp[fd])
		return (0);
	if (ft_strchr(tmp[fd], '\n'))
	{
		*(tmp[fd] + ft_strcspn(tmp[fd], "\n")) = '\0';
		*line = ft_strdup(tmp[fd]);
		tmp_h = ft_strdup(ft_strchr(tmp[fd], '\0') + 1);
		free(tmp[fd]);
		tmp[fd] = ft_strdup(tmp_h);
		free(tmp_h);
	}
	else
	{
		*line = ft_strdup(tmp[fd]);
		ft_strclr(tmp[fd]);
	}
	return (1);
}

/*
** GNL(get next line)
** Return a line up to a new line read with a file descriptor
** =============================================================
** Before the main function:
** Check for valid input of fd or read for errors. Return -1 if so.
** Main function description:
** Using fd as index, if our array is empty, allocate memory in a
** static array using fd as index.
** While checking for a newline '\n' in that array,
** read and join what's read into that array w/ user defined buff size.
** Using the return of read as index, null-terminate the buffer,
** declaring all the characters that has been read.
** If nothing is read then break out of the loop.
** Before copying the buffer to our main array, with a temp pointer,
** point it to our array[fd] earlier so we can free it later.
** Join the buffer and the value of our pointer to update array[fd]
** Free the old array[fd] by freeing the pointer.
** Pass the main array, line, and fd value to use next in ret_line().
*/

int	get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	int			n_bytes;
	static char	*tmp[FD_LIMIT];
	char		*tmp_h;

	if (fd == -1 || fd > FD_LIMIT || read(fd, buffer, 0) == -1)
		return (-1);
	if (!(tmp[fd]))
		tmp[fd] = ft_strnew(0);
	while (!(ft_strchr(tmp[fd], '\n')))
	{
		n_bytes = read(fd, buffer, BUFF_SIZE);
		buffer[n_bytes] = '\0';
		if (n_bytes == 0)
			break ;
		tmp_h = tmp[fd];
		tmp[fd] = ft_strjoin(tmp_h, buffer);
		free(tmp_h);
	}
	return (ret_line(tmp, line, fd));
}
