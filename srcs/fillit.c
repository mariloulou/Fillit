/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:36:57 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/09 17:48:42 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

/*
** The entry is valid; result is to be malloc-ed.
** The entry has the '#' characters replaced with letters already.
*/

static int	square_gen(int size, char **res)
{
	int		line;
	int		i;

	res = (char**)malloc(sizeof(*res) * (size + 1));
	if (!res)
		return (-1);
	line = 0;
	while (line < size)
	{
		res[line] = (char*)malloc(sizeof(**res) * (size + 1));
		if (!res[line])
			return (-1);
		i = 0;
		while (i < size)
		{
			res[line][i] = '.';
			i++;
		}
		res[line][size] = '\0';
		line++;
	}
	res[size] = NULL;
	return (0);
}

char		**fillit(char *entry)
{
	(void)entry;
	(void)square_gen(0, NULL);
	return (NULL);
}
