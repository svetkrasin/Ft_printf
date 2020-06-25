/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:21:07 by skrasin           #+#    #+#             */
/*   Updated: 2020/06/08 17:41:34 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

static inline void	*ft_bytememset(void *d, int c, size_t len)
{
	register unsigned char *dst;

	dst = d;
	while (len-- != 0)
		*dst++ = c;
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

static inline void	*ft_optmemset(void *dst, int c, size_t *l)
{
	register size_t				xl;
	register const unsigned OP_T	rep_c = ft_repcset(c);

	dst = ft_optalignmemset(dst, c, l);
	xl = *l / (OPT_SIZE * 8);
	while (xl-- != 0)
	{
		((unsigned OP_T *)dst)[0] = rep_c;
		((unsigned OP_T *)dst)[1] = rep_c;
		((unsigned OP_T *)dst)[2] = rep_c;
		((unsigned OP_T *)dst)[3] = rep_c;
		((unsigned OP_T *)dst)[4] = rep_c;
		((unsigned OP_T *)dst)[5] = rep_c;
		((unsigned OP_T *)dst)[6] = rep_c;
		((unsigned OP_T *)dst)[7] = rep_c;
		dst = (void *)((OP_T)dst + 8 * OPT_SIZE);
	}
	xl = (*l & (OPT_SIZE * 8 - 1)) / OPT_SIZE;
	while (xl-- != 0)
	{
		((unsigned OP_T *)dst)[0] = rep_c;
		dst = (void *)((OP_T)dst + OPT_SIZE);
	}
	*l &= OPT_MASK;
	return (dst);
}

void		*ft_memset(void *b, int c, size_t len)
{
	void			*dst;
	size_t *const	nbytes = &len;

	dst = b;
	c = (unsigned char)c;
	if (len >= OPT_SIZE)
		dst = ft_optmemset(dst, c, nbytes);
	if (len != 0)
		dst = ft_bytememset(dst, c, len);
	return (b);
}
