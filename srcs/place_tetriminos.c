/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassar <mcassar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:23:05 by mcassar           #+#    #+#             */
/*   Updated: 2016/12/10 18:30:05 by mcassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	place_tetri(char **map, int i, int j, char *tetri)
{
	if (map[i][j] != '.' || *tetri == '.')
		return (1);
	if (map[i][j] == '.' && *tetri != '.')
		map[i][j] = *tetri;
	return (0);
}

void	check_place_ext(t_struct *s, int *j)
{
	*j = *j + 1;
	s->block = s->block + 1;
}

int		check_place(char **map, int i, int j, char *tetri)
{
	t_struct s;
	
	s.savej = j;
	s.block = 0;
	while (s.block < 4 && *tetri != '\0')
	{
		while (*tetri == '.')
		{
			tetri++;
			(map[i][j] == '.' && j = 0;) ? j++ : 0;
		}
		if (place_tetri(map, i, j, tetri) == 1)
			return(0);
		check_place_ext(&s, &j);
		tetri++;
		while (*tetri == '.')
			tetri++;
		if (*tetri == '\n')
		{
			i++;
			j = s.savej;
			tetri++;
		}
	}
	return (s.block);
}

int		place_tetriminos(char **map, int i, int j, char *tetri)
{
	if (check_place(map, i, j, tetri) == 4)
		return(0);
	else
		return(1);
}
