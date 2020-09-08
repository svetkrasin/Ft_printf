/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:08:12 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/01 20:29:39 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <sys/_types/_null.h>

static inline const void	*ft_bytememchr(const void *str, int c, size_t n)
{
	register const unsigned char	*s;

	s = (const unsigned char *)str;
	while (n != 0 && *s != c)
	{
		++s;
		--n;
	}
	return (n ? s : NULL);
}

static inline const void	*ft_optmemchr(
	const void *str,
	int c,
	size_t *l,
	size_t long_size
)
{
	register size_t					xl;
	register const unsigned long	rep_c = ft_repcset(c);
	register unsigned long			w;
	register const unsigned long	*s;

	xl = ft_optmemalign(str);
	if (xl != 0 && (s = ft_bytememchr(str, c, xl)) != NULL)
		return (s);
	s = (const unsigned long *)((const unsigned char *)str + xl);
	*l -= xl;
	xl = *l / long_size;
	while (xl != 0)
	{
		w = *s ^ rep_c;
		if ((((w - REP_01L) & ~w) & (REP_01L << (long_size - 1))) != 0)
			break ;
		++s;
		--xl;
	}
	*l = xl ? long_size : *l & (long_size - 1);
	return (s);
}

void						*ft_memchr(const void *str, int c, size_t n)
{
	const size_t	long_size = sizeof(long);
	size_t *const	nbytes = &n;

	c = (unsigned char)c;
	if (n > long_size)
		str = ft_optmemchr(str, c, nbytes, long_size);
	return (n != 0 ? (void *)ft_bytememchr(str, c, n) : NULL);
}
