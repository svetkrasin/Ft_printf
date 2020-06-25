/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:12:30 by skrasin           #+#    #+#             */
/*   Updated: 2020/06/08 17:36:26 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

static inline void	ft_bytememcpy(const void **ds, const void **sr, size_t *nbytes,
																	size_t n)
{
	register unsigned char		*dst;
	register const unsigned char *src;

	dst = *(unsigned char **)ds;
	src = *(const unsigned char **)sr;
	*nbytes -= n;
	while (n-- != 0)
		*dst++ = *src++;
	*(unsigned char **)ds = dst;
	*(const unsigned char **)sr = src;
}

static inline void	ft_8optmemcpy(const void **ds, const void **sr, size_t *nbytes)
{
	register void		*dst;
	register const void	*src;
	register size_t		n;

	n = ft_memaligncmp((const void **)ds, sr, *nbytes, OPT_SIZE);
	ft_bytememcpy(ds, sr, nbytes, n);
	n = *nbytes / (OPT_SIZE * 8);
	dst = *(void **)ds;
	src = *(const void **)sr;
	while (n-- != 0)
	{
		((unsigned OP_T *)dst)[0] = ((unsigned OP_T *)src)[0];
		((unsigned OP_T *)dst)[1] = ((unsigned OP_T *)src)[1];
		((unsigned OP_T*)dst)[2] = ((unsigned OP_T *)src)[2];
		((unsigned OP_T *)dst)[3] = ((unsigned OP_T *)src)[3];
		((unsigned OP_T *)dst)[4] = ((unsigned OP_T *)src)[4];
		((unsigned OP_T *)dst)[5] = ((unsigned OP_T *)src)[5];
		((unsigned OP_T*)dst)[6] = ((unsigned OP_T *)src)[6];
		((unsigned OP_T *)dst)[7] = ((unsigned OP_T *)src)[7];
		dst = (void *)((OP_T)dst + 8 * OPT_SIZE);
		src = (void *)((OP_T)src + 8 * OPT_SIZE);
	}
	*(void **)ds = dst;
	*(const void **)sr = src;
	*nbytes &= OPT_SIZE * 8 - 1;
}

static inline void	ft_optmemcpy(const void **ds, const void **sr, size_t *nbytes)
{
	register unsigned OP_T			*dst;
	register const unsigned OP_T	*src;
	register size_t					n;

	n = ft_memaligncmp((const void **)ds, sr, *nbytes, OPT_SIZE);
	ft_bytememcpy(ds, sr, nbytes, n);
	n = *nbytes / OPT_SIZE;
	*nbytes &= OPT_MASK;
	dst = *(unsigned OP_T **)ds;
	src = *(const unsigned OP_T **)sr;
	while (n-- != 0)
		*dst++ = *src++;
	*(unsigned OP_T **)ds = dst;
	*(const unsigned OP_T **)sr = src;
}

void		*ft_memcpy(void *ds, const void *sr, size_t n)
{
	const void *const	tmp = ds;
	const void			**dst = (const void **)&tmp;
	const void			**src = &sr;
	size_t *const		nbytes = &n;

	if (n == 0 || ds == sr)
		return (ds);
	if (n >= 8 * OPT_SIZE)
		ft_8optmemcpy(dst, src, nbytes);
	if (n >= OPT_SIZE)
		ft_optmemcpy(dst, src, nbytes);
	if (n != 0)
		ft_bytememcpy(dst, src, nbytes, n);
	return (ds);
}
