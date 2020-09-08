/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:21:07 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/01 20:24:09 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

static inline void	*ft_bytememset(void *d, int c, size_t len)
{
	register unsigned char *dst;

	dst = d;
	while (len-- != 0)
		*dst++ = (unsigned char)c;
	return (dst);
}

static inline void	*ft_optalignmemset(void *dst, int c, size_t *l)
{
	size_t xl;

	if ((xl = ft_optmemalign(dst)) != 0)
	{
		*l -= xl;
		return (ft_bytememset(dst, c, xl));
	}
	else
		return (dst);
}

static inline void	*ft_optmemset(void *dst, int c, size_t *l, size_t long_size)
{
	register size_t					xl;
	register const unsigned long	rep_c = ft_repcset(c);

	dst = ft_optalignmemset(dst, c, l);
	xl = *l / (long_size * 8);
	while (xl-- != 0)
	{
		((unsigned long *)dst)[0] = rep_c;
		((unsigned long *)dst)[1] = rep_c;
		((unsigned long *)dst)[2] = rep_c;
		((unsigned long *)dst)[3] = rep_c;
		((unsigned long *)dst)[4] = rep_c;
		((unsigned long *)dst)[5] = rep_c;
		((unsigned long *)dst)[6] = rep_c;
		((unsigned long *)dst)[7] = rep_c;
		dst = (void *)((long)dst + 8 * (long)long_size);
	}
	xl = (*l & (long_size * 8 - 1)) / long_size;
	while (xl-- != 0)
	{
		((unsigned long *)dst)[0] = rep_c;
		dst = (void *)((long)dst + (long)long_size);
	}
	*l &= long_size - 1;
	return (dst);
}

void				*ft_memset(void *b, int c, size_t len)
{
	const size_t	long_size = sizeof(long);
	size_t *const	nbytes = &len;
	void			*dst;

	dst = b;
	c = (unsigned char)c;
	if (len >= long_size)
		dst = ft_optmemset(dst, c, nbytes, long_size);
	if (len != 0)
		dst = ft_bytememset(dst, c, len);
	return (b);
}
