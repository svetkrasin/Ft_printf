/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:12:30 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/01 20:23:56 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

static inline void	ft_bytememcpy(
	void **ds,
	const void **sr,
	size_t *nbytes,
	size_t n
)
{
	register unsigned char			*dst;
	register const unsigned char	*src;

	dst = *(unsigned char **)ds;
	src = *(const unsigned char **)sr;
	*nbytes -= n;
	while (n-- != 0)
		*dst++ = *src++;
	*(unsigned char **)ds = dst;
	*(const unsigned char **)sr = src;
}

static inline void	ft_8optmemcpy(
	void **ds,
	const void **sr,
	size_t *nbytes,
	size_t long_8size
)
{
	register void		*dst;
	register const void	*src;
	register size_t		n;

	n = ft_memaligncmp((const void *const *)ds, sr, *nbytes, long_8size / 8);
	ft_bytememcpy(ds, sr, nbytes, n);
	n = *nbytes / (long_8size);
	dst = *ds;
	src = *(const void **)sr;
	while (n-- != 0)
	{
		((long *)dst)[0] = ((const long *)src)[0];
		((long *)dst)[1] = ((const long *)src)[1];
		((long *)dst)[2] = ((const long *)src)[2];
		((long *)dst)[3] = ((const long *)src)[3];
		((long *)dst)[4] = ((const long *)src)[4];
		((long *)dst)[5] = ((const long *)src)[5];
		((long *)dst)[6] = ((const long *)src)[6];
		((long *)dst)[7] = ((const long *)src)[7];
		dst = (void *)((long)dst + (long)long_8size);
		src = (void *)((long)src + (long)long_8size);
	}
	*(void **)ds = dst;
	*(const void **)sr = src;
	*nbytes &= long_8size - 1;
}

static inline void	ft_optmemcpy(
	void **ds,
	const void **sr,
	size_t *nbytes,
	size_t long_size
)
{
	register unsigned long			*dst;
	register const unsigned long	*src;
	register size_t					n;

	n = ft_memaligncmp((const void *const *)ds, sr, *nbytes, long_size);
	ft_bytememcpy(ds, sr, nbytes, n);
	n = *nbytes / long_size;
	*nbytes &= long_size - 1;
	dst = *(unsigned long **)ds;
	src = *(const unsigned long **)sr;
	while (n-- != 0)
		*dst++ = *src++;
	*(unsigned long **)ds = dst;
	*(const unsigned long **)sr = src;
}

void				*ft_memcpy(void *ds, const void *sr, size_t n)
{
	const size_t	long_size = sizeof(long);
	const void		**src = &sr;
	size_t *const	nbytes = &n;
	void			**dst;
	void			*tmp;

	if (n == 0 || ds == sr)
		return (ds);
	tmp = ds;
	dst = &tmp;
	if (n >= 8 * long_size)
		ft_8optmemcpy(dst, src, nbytes, long_size * 8);
	if (n >= long_size)
		ft_optmemcpy(dst, src, nbytes, long_size);
	if (n != 0)
		ft_bytememcpy(dst, src, nbytes, n);
	return (ds);
}
