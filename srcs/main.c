/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 08:20:59 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/10 15:50:46 by mcassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static void		free_tab(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int				main(int argc, char **argv)
{
	char	*entry;
	char	**result;

	if (argc != 2)
	{
		ft_putendl_fd("usage: fillit tetriminos_file", 2);
		return (-1);
	}
	if ((entry = parse_input(argv[1])) == NULL)
	{
		ft_putstr("error");
		return (-1);
	}
	result = fillit(entry);
//	ft_putstr(result);
	free(entry);
	free_tab(result);
	return (0);
}
