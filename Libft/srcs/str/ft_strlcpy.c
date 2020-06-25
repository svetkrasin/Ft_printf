/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 20:12:00 by svet              #+#    #+#             */
/*   Updated: 2020/05/19 12:09:10 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t n;

	if (!dst || !src)
		return (0);
	n = ft_strlen(src);
	if (dstsize != 0)
	{
		if (n < dstsize - 1)
			ft_memcpy(dst, src, n + 1);
		else
		{
			ft_memcpy(dst, src, dstsize - 1);
			dst[dstsize - 1] = '\0';
		}
	}
	return (n);
}
