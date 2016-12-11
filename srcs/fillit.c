/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:36:57 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/11 20:06:40 by gudemare         ###   ########.fr       */
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

	size = ft_strlen(*src);
	if (!(res = (char**)malloc(sizeof(*res) * (size + 2))))
		return (NULL);
	line = 0;
	while (line <= size)
	{
		if (!(res[line] = (char*)malloc(sizeof(*res) * (size + 1))))
		{
			free_tab(res);
			return (NULL);
		}
		ft_memcpy((void*)res[line], (void*)src[line], (size_t)(size + 1));
		line++;
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

static char		**backtrack_fill(char **res, char *tetri)
{
	int		try;
	char	**map;
	char	**sol;

	if (!(map = sqrdup(res)))
		return (NULL);
	try = 0;
	while (place_tetriminos(map, tetri, try) != 0)
	{
		if (tetri[20] == '\0')
			return (map);
		if ((sol = backtrack_fill(map, tetri + 21)) == NULL)
		{
			free_tab(map);
			map = sqrdup(res);
			try++;
		}
		else
		{
			free_tab(map);
			return (sol);
		}
	}
	free_tab(map);
	return (NULL);
}

char			**fillit(char *entry)
{
	char	**res;
	int		size;
	int		filled;

	filled = 0;
	size = ft_sqrt(((ft_strlen(entry) + 1) / 21) * 4);
	while (1)
	{
		res = sqrgen(size);
		if ((res = backtrack_fill(res, entry)) != NULL)
			return (res);
		free_tab(res);
		size++;
	}
	return (NULL);
}
