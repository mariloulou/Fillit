/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:28:22 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/07 13:32:29 by gudemare         ###   ########.fr       */
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

/*static int	parse_tetriminos(char *s)
{
	return (0);
}*/

static int	verify_format(char *s)
{
	int		i;

	ft_putendl("Verifying..."); //
	if (((ft_strlen(s) - 20) % 21) != 0)
		return (0);
	ft_putendl("Good character number"); //
	while (*s)
	{
		i = 0;
		ft_putendl("Checking tetrimino # ..."); //
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
		if (s[i] != '\n' && s[i] != '\0')
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
		else
			ft_putstr("Passed\n"); //
	}
	close(fd);
	return (entry);
}
