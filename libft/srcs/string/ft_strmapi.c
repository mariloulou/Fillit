/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 22:54:33 by gudemare          #+#    #+#             */
/*   Updated: 2016/11/13 12:33:55 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		index;
	char				*dst;

	if (!s)
		return (NULL);
	dst = (char *)malloc(sizeof(*dst) * (ft_strlen(s) + 1));
	if (!dst)
		return (NULL);
	index = 0;
	while (s[index])
	{
		dst[index] = f(index, s[index]);
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
