/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 23:00:16 by gudemare          #+#    #+#             */
/*   Updated: 2016/11/22 03:28:48 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (!s || !*s)
		return (NULL);
	dst = (char *)malloc(sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	dst[0] = s[start];
	dst[len] = '\0';
	if (len > 0)
		len--;
	while (len > 0)
	{
		dst[len] = s[start + len];
		len--;
	}
	return (dst);
}
