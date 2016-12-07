/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 22:43:00 by gudemare          #+#    #+#             */
/*   Updated: 2016/11/12 22:46:14 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dst;

	dst = (char *)malloc(sizeof(*dst) * size + 1);
	if (!dst)
		return (NULL);
	dst[size] = '\0';
	ft_strclr(dst);
	return (dst);
}
