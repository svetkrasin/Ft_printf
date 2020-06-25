/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:08:12 by skrasin           #+#    #+#             */
/*   Updated: 2020/06/08 17:57:51 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <sys/_types/_null.h>

static inline void	*ft_bytememchr(const void *str, int c, size_t n)
{
	register const unsigned char	*s;

	s = (const unsigned char *)str;
	while (n != 0 && *s != c)
	{
		++s;
		--n;
	}
	return (n ? (void *)s : NULL);
}

static inline void	*ft_optmemchr(const void *str, int c, size_t *l)
{
	register size_t					xl;
	register const unsigned OP_T	rep_c = ft_repcset(c);
	register unsigned OP_T			w;
	register const unsigned OP_T	*s;

	xl = ft_optmemalign(str);
	if (xl != 0 && (s = ft_bytememchr(str, c, xl)) != NULL)
		return ((void *)s);
	s = (const unsigned OP_T *)((const unsigned char *)str + xl);
	*l -= xl;
	xl = *l / OPT_SIZE;
	while (xl != 0)
	{
		w = *s ^ rep_c;
		if ((((w - REP_01L) & ~w) & (REP_01L << OPT_MASK)) != 0)
			break ;
		++s;
		--xl;
	}
	*l = xl ? OPT_SIZE : *l & OPT_MASK;
	return ((void *)s);
}

void		*ft_memchr(const void *str, int c, size_t n)
{
	size_t *const	nbytes = &n;

	c = (unsigned char)c;
	if (n > OPT_SIZE)
		str = ft_optmemchr(str, c, nbytes);
	return (n != 0 ? ft_bytememchr(str, c, n) : NULL);
}
