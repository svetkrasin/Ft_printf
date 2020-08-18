/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:20:00 by skrasin           #+#    #+#             */
/*   Updated: 2020/07/20 15:01:15 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const size_t	ndst = ft_strlen(dst);
	const size_t	nsrc = ft_strlen(src);
	size_t			l;

	l = ndst + 1;
	if (l < dstsize)
	{
		l = nsrc > (dstsize - l) ? (dstsize - l) : nsrc;
		ft_memcpy(dst + ndst, src, l);
		dst[ndst + l] = '\0';
	}
	return (nsrc + (dstsize < ndst ? dstsize : ndst));
}
