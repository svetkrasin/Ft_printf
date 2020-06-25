/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:41:57 by skrasin           #+#    #+#             */
/*   Updated: 2020/06/08 17:38:56 by svet             ###   ########.fr       */
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

static inline void	ft_optmemmove(void  **ds, const void **sr, size_t *nbytes)
{
	register unsigned OP_T			*dst;
	register const unsigned OP_T	*src;
	register size_t					n;

	n = ft_memaligncmp_bwd((const void *const *const)ds, sr, *nbytes, OPT_SIZE);
	ft_bytememmove(ds, sr, nbytes, n);
	n = *nbytes / OPT_SIZE;
	*nbytes &= OPT_MASK;
	dst = *(unsigned OP_T **)ds;
	src = *(const unsigned OP_T **)sr;
	while (n-- != 0)
		*--dst = *--src;
	*(unsigned OP_T **)ds = dst;
	*(const unsigned OP_T **)sr = src;
}

void		*ft_memmove(void *ds, const void *sr, size_t len)
{
	void				**dst;
	const void			**src;
	size_t *const		nbytes = &len;
	void 				*tmp;

	if (len == 0 || ds == sr)
		return (ds);
	if ((size_t)((OP_T)ds - (OP_T)sr) >= len)
		ft_memcpy(ds, sr, len);
	else
	{
		tmp = (void *)((OP_T)ds + len);
		dst = &tmp;
		sr = (void *)((OP_T)sr + len);
		src = &sr;
		if (len >= OPT_SIZE)
			ft_optmemmove(dst, src, nbytes);
		if (len != 0)
			ft_bytememmove(dst, src, nbytes, len);
	}
	return (ds);
}
