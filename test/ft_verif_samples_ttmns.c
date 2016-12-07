/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_samples_ttmns.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 09:58:38 by mcassar           #+#    #+#             */
/*   Updated: 2016/12/06 09:07:35 by mcassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 4096

int	ifblock(char **tab, int i, int j, int link)
{
	while (tab[i][j] != '\0')
	{
		if (tab[i][j] == '#' && tab[i][j + 1] == '#')
			link++;
		if (i < ft_tl(tab) - 1 && tab[i][j] == '#' && tab[i + 1][j] == '#')
			link++;
		if (i > 0 && tab[i][j] == '#' && tab[i - 1][j] == '#')
			link++;
		if (tab[i][j] == '#' && tab[i][j - 1] == '#')
			link++;
		j++;
	}
	return (link);
}

int	count_links(char **tab)
{
	int i;
	int j;
	int link;
	int save;

	i = 0;
	j = 0;
	link = 0;
	save = 0;
	while (tab[i])
	{
		while (save < 4)
		{
			link = ifblock(tab, i, j, link);
			i++;
			save++;
			j = 0;
		}
		if (link != 6 && link != 8)
			return (-1);
		link = 0;
		save = 0;
	}
	return (0);
}

int	ft_verif_samples_ttmns(void)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	char	**tab;

	if (ft_verif_samples_format() == -1)
		return (-1);
	fd = open("samples_fillit", O_RDONLY);
	read(fd, buf, BUF_SIZE);
	tab = ft_strsplit(buf, '\n');
	if (count_links(tab) == -1)
		return(-1);
	return (0);
}
