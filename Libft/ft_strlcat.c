/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:20:00 by skrasin           #+#    #+#             */
/*   Updated: 2019/09/20 17:45:38 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t n;
	size_t res;

	n = ft_strlen(dst);
	res = ft_strlen(src);
	if (dstsize < n)
		res += dstsize;
	else
		res += n;
	while (*src && n + 1 < dstsize)
	{
		dst[n++] = *src;
		src++;
	}
	dst[n] = '\0';
	return (res);
}
