/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 08:14:13 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/11 19:01:00 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

char	*parse_input(char *filename);
char	**fillit(char *entry);
int		place_tetriminos(char **map, char *tetri, int pos);
void	free_tab(char **tab);
void	ft_puttab(char **tab);

#endif
