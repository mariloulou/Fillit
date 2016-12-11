/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 16:04:27 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/11 21:50:00 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_place(char **map, int i, char *tetri)
{
	int		block;
	int		t;

	t = 0;
	block = 0;
	while (block < 4)
	{
		if (tetri[t] >= 'A' && tetri[t] <= 'Z')
		{
			if (map[t / 5][i + (t % 5)] != '.')
				return (0);
			block++;
		}
		t++;
	}
	return (1);
}

static void		place_tetri_point(char **map, int i, char *tetri)
{
	int		block;
	int		t;

	t = 0;
	block = 0;
	while (block < 4)
	{
		if (tetri[t] >= 'A' && tetri[t] <= 'Z')
		{
			map[t / 5][i + (t % 5)] = tetri[t];
			block++;
		}
		t++;
	}
}

static void		next_case(char **map, int *j, int *i)
{
	if (map[*j][*i + 1] == '\0')
	{
		*j += 1;
		*i = 0;
	}
	else
		*i += 1;
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
		while (!check_place(map + j, i, tetri))
		{
			if (map[j + 1][0] == '\0')
				return (0);
			next_case(map, &j, &i);
		}
		count++;
		if (count > pos)
			break ;
		if (map[j + 1][0] == '\0')
			return (0);
		next_case(map, &j, &i);
	}
	place_tetri_point(map + j, i, tetri);
	return (1);
}
