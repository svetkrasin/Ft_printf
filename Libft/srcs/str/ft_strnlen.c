/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 14:58:35 by svet              #+#    #+#             */
/*   Updated: 2020/07/10 14:52:04 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

static inline int	ft_testoptnstrlen(const unsigned OP_T *uls, const size_t n)
{
	register const char *const	c = (const char *)uls;
	register size_t				i;

	i = 0;
	while (i < n)
	{
		if (c[i] == '\0')
			return (i);
		++i;
	}
	return (-1);
}

size_t				ft_strnlen(const char *str, size_t n)
{
	const char						*s = str;
	register const unsigned OP_T	*uls;
	register int					x;

	x = ft_optmemalign(str);
	while (x-- != 0 && n != 0)
	{
		if (*s++ == '\0')
			return (s - str - 1);
		--n;
	}
	uls = (unsigned OP_T *)s;
	while (n >= OPT_SIZE)
	{
		if (((*uls - REP_01L) & ((~*uls) & REP_08L)) != 0)
			if ((x = ft_testoptnstrlen(uls, OPT_SIZE)) != -1)
				return ((const char *)uls - str + x);
		++uls;
		n -= OPT_SIZE;
	}
	x = ft_testoptnstrlen(uls, n);
	if (x != -1)
		return ((const char *)uls - str + x);
	return ((const char *)uls - str + n);
}
