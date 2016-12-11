/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 16:04:27 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/11 19:57:57 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_place(char **map, int j, int i, char *tetri)
{
	int		block;
	int		t;

	t = 0;
	block = 0;
	while (block < 4)
	{
		if (ft_isalpha(tetri[t]))
		{
			if (map[j + (t / 5)][i + (t % 5)] == '.')
				block++;
			else
				return (0);
		}
		t++;
	}
	return (1);
}

static int		place_tetri_point(char **map, int j, int i, char *tetri)
{
	int		block;
	int		t;

	t = 0;
	block = 0;
	while (block < 4)
	{
		if (ft_isalpha(tetri[t]))
		{
			map[j + (t / 5)][i + (t % 5)] = tetri[t];
			block++;
		}
		t++;
	}
	return (1);
}

static int		next_case(char **map, int *j, int *i)
{
	*i += 1;
	if (map[*j][*i] == '\0')
	{
		if (map[*j + 1][0] == '\0')
			return (0);
		*j += 1;
		*i = 0;
	}
	return (1);
}

int				place_tetriminos(char **map, char *tetri, int pos)
{
	int		j;
	int		i;
	int		count;

	count = 0;
	j = 0;
	i = 0;
	while (count <= pos)
	{
		while (!check_place(map, j, i, tetri))
			if (next_case(map, &j, &i) == 0)
				return (0);
		count++;
		if (count > pos)
			break ;
		if (next_case(map, &j, &i) == 0)
			return (0);
	}
	place_tetri_point(map, j, i, tetri);
	return (1);
}
