/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:41:57 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/01 20:26:38 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

static inline void	ft_bytememmove(void **ds, const void **sr, size_t *len,
																	size_t n)
{
	register unsigned char			*dst;
	register const unsigned char	*src;

	dst = *(unsigned char **)ds;
	src = *(const unsigned char **)sr;
	*len -= n;
	while (n-- != 0)
		*--dst = *--src;
}

static inline void	ft_optmemmove(
	void **ds,
	const void **sr,
	size_t *nbytes,
	size_t long_size
)
{
	register unsigned long			*dst;
	register const unsigned long	*src;
	register size_t					n;

	n = ft_memaligncmp_bwd((const void *const *const)ds, sr, *nbytes,
																	long_size);
	ft_bytememmove(ds, sr, nbytes, n);
	n = *nbytes / long_size;
	*nbytes &= long_size - 1;
	dst = *(unsigned long **)ds;
	src = *(const unsigned long **)sr;
	while (n-- != 0)
		*--dst = *--src;
	*(unsigned long **)ds = dst;
	*(const unsigned long **)sr = src;
}

void				*ft_memmove(void *ds, const void *sr, size_t len)
{
	const size_t	long_size = sizeof(long);
	size_t *const	nbytes = &len;
	void			**dst;
	const void		**src;
	void			*tmp;

	if (len == 0 || ds == sr)
		return (ds);
	if ((size_t)((long)ds - (long)sr) >= len)
		ft_memcpy(ds, sr, len);
	else
	{
		tmp = (void *)((long)ds + (long)len);
		dst = &tmp;
		sr = (void *)((long)sr + (long)len);
		src = &sr;
		if (len >= long_size)
			ft_optmemmove(dst, src, nbytes, long_size);
		if (len != 0)
			ft_bytememmove(dst, src, nbytes, len);
	}
	return (ds);
}
