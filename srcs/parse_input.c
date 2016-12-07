/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:28:22 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/07 12:08:38 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** parse_input() reads the fd and returns the entry as a malloc-ed char*
** if it is valid and returns NULL otherwise.
** 546 is the longest valid entry possible (26 valid pieces).
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "fillit.h"

#define BUF_SIZE 546

static int	parse_tetriminos(char *tetri)
{
	(void)tetri;
	return (0);
}

static int	verify_format(char *entry)
{
	(void)entry;
	parse_tetriminos(entry);
	return (0);
}

char		*parse_input(char *filename)
{
	int		fd;
	char	*entry;

	if ((fd = open(filename, O_RDONLY)) == -1
		|| (entry = (char*)malloc(sizeof(*entry) * BUF_SIZE)) == NULL)
		return (NULL);
	if (read(fd, entry, BUF_SIZE) != 0)
		entry = NULL;
	else
	{
		if (!verify_format(entry))
			entry = NULL;
	}
	close(fd);
	return (entry);
}
