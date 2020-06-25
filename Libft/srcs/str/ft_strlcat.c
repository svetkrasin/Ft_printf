/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:20:00 by skrasin           #+#    #+#             */
/*   Updated: 2020/05/19 12:07:48 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const size_t	ndst = ft_strlen(dst);
	const size_t	nsrc = ft_strlen(src);
	size_t			l;

	l = ndst + 1;
	if (l < dstsize)
	{
		if (nsrc > dstsize - l)
			l = dstsize - l;
		else
			l = nsrc;
		ft_memcpy(dst + ndst, src, l);
		dst[ndst + l] = '\0';
	}
	if (dstsize < ndst)
		l = nsrc + dstsize;
	else
		l = nsrc + ndst;
	return (l);
}
