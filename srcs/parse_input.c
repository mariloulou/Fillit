/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:28:22 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/11 19:57:07 by gudemare         ###   ########.fr       */
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
** tetrimino.
** parse_tetriminos_block() is a recursive function to check the tetrimino
** itself. It transforms the '#' in letters as it goes.
** tidy_tetriminos() pulls the tetriminos in the upper left corner.
*/

static void	tidy_tetriminos(char *s)
{
	int		i;

	while (s[0] == '.' && s[1] == '.' && s[2] == '.' && s[3] == '.')
	{
		i = 0;
		while (i < 20)
		{
			if ((i + 1) % 5 != 0)
				s[i] = (i < 15) ? s[i + 5] : '.';
			i++;
		}
	}
	while (s[0] == '.' && s[5] == '.' && s[10] == '.' && s[15] == '.')
	{
		i = 0;
		while (i < 20)
		{
			if ((i + 1) % 5 != 0)
				s[i] = ((i + 2) % 5 != 0) ? s[i + 1] : '.';
			i++;
		}
	}
}

static int	parse_tetriminos_block(char *s, int i, int tetri_nb)
{
	int		nb;

	if (s[i] != '#')
		return (0);
	nb = 1;
	s[i] = (char)tetri_nb + 'A';
	if (i > 0 && s[i - 1] == '#')
		nb += parse_tetriminos_block(s, i - 1, tetri_nb);
	if (i > 4 && s[i - 5] == '#')
		nb += parse_tetriminos_block(s, i - 5, tetri_nb);
	if (i < 16 && s[i + 5] == '#')
		nb += parse_tetriminos_block(s, i + 5, tetri_nb);
	if (i < 20 && s[i + 1] == '#')
		nb += parse_tetriminos_block(s, i + 1, tetri_nb);
	return (nb);
}

static int	parse_tetriminos(char *s)
{
	static int	tetri_nb = -1;
	int			i;

	i = 0;
	tetri_nb++;
	while (s[i] != '#' && s[i])
		i++;
	if (!s[i] || parse_tetriminos_block(s, i, tetri_nb) != 4)
		return (0);
	tidy_tetriminos(s);
	return (1);
}

static int	verify_format(char *s)
{
	int		i;

	if (((ft_strlen(s) - 20) % 21) != 0)
		return (0);
	while (1)
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
		if (s[i] == '\0')
			return (1);
		s += 21;
	}
}

char		*parse_input(char *filename)
{
	int		fd;
	int		len;
	char	*entry;

	if ((fd = open(filename, O_RDONLY)) == -1
		|| (entry = (char*)malloc(sizeof(*entry) * (BUF_SIZE + 1))) == NULL)
		return (NULL);
	if ((len = read(fd, entry, BUF_SIZE)) == -1)
		entry = NULL;
	else
	{
		entry[len] = '\0';
		if (!verify_format(entry))
		{
			free(entry);
			entry = NULL;
		}
	}
	close(fd);
	return (entry);
}
