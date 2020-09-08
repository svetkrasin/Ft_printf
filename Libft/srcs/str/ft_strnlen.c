/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 14:58:35 by svet              #+#    #+#             */
/*   Updated: 2020/09/01 20:16:04 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

static inline int	ft_testoptnstrlen(const unsigned long *uls, const size_t n)
{
	register const char *const	c = (const char *)uls;
	register size_t				i;

	i = 0;
	while (i < n)
	{
		if (c[i] == '\0')
			return ((int)i);
		++i;
	}
	return (-1);
}

size_t				ft_strnlen(const char *str, size_t n)
{
	const size_t					long_size = sizeof(long);
	const char						*s = str;
	register const unsigned long	*uls;
	register int					x;

	x = (int)ft_optmemalign(str);
	while (x-- != 0 && n != 0)
	{
		if (*s++ == '\0')
			return ((size_t)(s - str - 1));
		--n;
	}
	uls = (const unsigned long *)s;
	while (n >= long_size)
	{
		if (((*uls - REP_01L) & ((~*uls) & REP_08L)) != 0)
			if ((x = ft_testoptnstrlen(uls, long_size)) != -1)
				return ((size_t)((const char *)uls - str + x));
		++uls;
		n -= long_size;
	}
	x = ft_testoptnstrlen(uls, n);
	if (x != -1)
		return ((size_t)((const char *)uls - str + x));
	return ((size_t)((const char *)uls - str + (long)n));
}
