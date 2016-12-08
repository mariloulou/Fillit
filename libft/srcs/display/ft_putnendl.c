/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:25:48 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/08 14:31:44 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnendl(char const *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] && i < n)
		i++;
	write(1, s, i);
	write(1, "\n", 1);
}
