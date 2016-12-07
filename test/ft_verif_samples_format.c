/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_samples_fillit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 09:45:33 by mcassar           #+#    #+#             */
/*   Updated: 2016/12/03 11:25:58 by mcassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 4096

int	format(char *buf)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (buf[i])
	{
		i = i + 4;
		if (buf[i] != '\n')
			return (-1);
		i++;
		j++;
		if (j == 5)
		{
			if (buf[i] != '\n' && buf[i] != '\0')
				return (-1);
			i++;
			j = 1;
		}
	}
	return (0);
}

int	carac(char *buf)
{
	int i;
	int block;

	i = 0;
	while (buf[i])
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (-1);
		i++;
	}
	i = 0;
	block = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			block++;
		if (buf[i] == '\n' && buf[i + 1] == '\n')
		{
			if (block != 4)
				return (-1);
			block = 0;
		}
		i++;
	}
	return (0);
}

int	ft_verif_samples_format(void)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open("samples_fillit", O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = read(fd, buf, BUF_SIZE);
	if (ret == 0)
		return (-1);
	if (format(buf) == -1)
		return (-1);
	if (carac(buf) == -1)
		return (-1);
	return (0);
}
