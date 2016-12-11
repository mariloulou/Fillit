/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:36:57 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/11 18:12:49 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

/*
** The entry is valid; result is to be malloc-ed.
** The entry has the '#' characters replaced with letters already.
*/

static char		**sqrdup(char **src)
{
	int		size;
	int		line;
	char	**res;
	int		i;

	size = ft_strlen(*src);
	if (!(res = (char**)malloc(sizeof(*res) * (size + 2))))
	{
		ft_putendl("MEMFAIL");
		return (NULL);
	}
	line = 0;
	while (line < size)
	{
		if (!(res[line] = ft_strdup(src[line])))
		{
			free_tab(res);
			ft_putendl("MEMFAIL");
			return (NULL);
		}
		line++;
	}
	if (!(res[size] = (char*)malloc(sizeof(**res) * (size + 1))))
	{
		free_tab(res);
		return (NULL);
	}
	i = 0;
	while (i <= size)
	{
		res[size][i] = '\0';
		i++;
	}
	res[size + 1] = NULL;
	return (res);
}

static char		**sqrgen(int size)
{
	char	**res;
	int		line;
	int		i;

	if (!(res = (char**)malloc(sizeof(*res) * (size + 2))))
		return (NULL);
	line = 0;
	while (line <= size)
	{
		if (!(res[line] = (char*)malloc(sizeof(**res) * (size + 1))))
		{
			free_tab(res);
			return (NULL);
		}
		i = 0;
		while (i < size)
		{
			res[line][i] = (line == size) ? '\0' : '.';
			i++;
		}
		res[line][size] = '\0';
		line++;
	}
	res[size + 1] = NULL;
	return (res);
}

static int		backtrack_fill(char **res, int size, char *entry, char ***solution)
{
	int		nb_tetri= ((ft_strlen(entry) - 20) / 21) + 1;
	int		nb_placed;
	char	**stock[nb_tetri];
	int		try = 0;

	(void)size;
	nb_placed = 0;
	while (nb_placed < nb_tetri)
	{
		if (place_tetriminos(res, entry, try) == 1)
		{
			stock[nb_placed] = res;
			ft_putendl("state :");
			ft_puttab(res);
			ft_putendl("");
			nb_placed++;
			res = sqrdup(res);
			entry += 21;
			try = 0;
		}
		else
		{
			ft_putendl("============Trying Backtracking...=====");
			if (nb_placed == 0)
				return (0);
			ft_putendl("Old state :");
			ft_puttab(res);
			ft_putendl("");
			nb_placed--;
			res = stock[nb_placed];
			ft_putendl("New state :");
			ft_puttab(res);
			ft_putendl("===================================================");
			entry -= 21;
			try++;
		}
	}
	*solution = res;
	return (1);
}

char			**fillit(char *entry)
{
	char	**res;
	int		size;
	int		filled;

	filled = 0;
	size = 2;
	ft_putendl(entry); //
	while (size < 15)
	{
		res = sqrgen(size);
		ft_putstr("Trying size ");
		ft_putnbr(size);
		ft_putendl("...");
		if (backtrack_fill(res, size, entry, &res) == 1)
			return (res);
		free_tab(res);
		size++;
	}
	return (NULL);
}
