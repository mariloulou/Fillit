/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:28:22 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/08 14:41:18 by gudemare         ###   ########.fr       */
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

/*
** parse_tetriminos() runs at the start of a complete, correctly formated
** tetrimino. It transforms the '#' in digits as it goes.
*/

static int	parse_tetriminos_block(char *s, int i, int tetri_nb)
{
	(void)s;
	(void)i;
	(void)tetri_nb;
	return (4);
}

static int	parse_tetriminos(char *s)
{
	static int	tetri_nb = -1;
	int			i;
	int			nb;

	i = 0;
	nb = 0;
	tetri_nb++;
	while (i < 20)
	{
		if (s[i] == '#')
			nb++;
		i++;
	}
	i = 0;
	while (s[i] != '#')
		i++;
	if (nb != 4 || parse_tetriminos_block(s, i, tetri_nb) != 4)
		return (0);
	return (1);
}

static int	verify_format(char *s)
{
	int		i;

	if (((ft_strlen(s) - 20) % 21) != 0)
		return (0);
	while (*s)
	{
		i = 0;
		while (i < 20)
		{
			while ((i + 1) % 5 != 0)
			{
				if (s[i] != '.' && s[i] != '#')
					return (0);
				i++;
			}
			if (s[i] != '\n')
				return (0);
			i++;
		}
		if (!parse_tetriminos(s) || (s[i] != '\n' && s[i] != '\0'))
			return (0);
		s += i + 1;
	}
	return (1);
}

char		*parse_input(char *filename)
{
	int		fd;
	char	*entry;

	if ((fd = open(filename, O_RDONLY)) == -1
		|| (entry = (char*)malloc(sizeof(*entry) * BUF_SIZE)) == NULL)
		return (NULL);
	if (read(fd, entry, BUF_SIZE) == -1)
		entry = NULL;
	else
	{
		if (!verify_format(entry))
			entry = NULL;
	}
	close(fd);
	return (entry);
}
