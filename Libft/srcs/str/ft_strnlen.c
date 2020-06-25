/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 14:58:35 by svet              #+#    #+#             */
/*   Updated: 2020/05/16 09:02:59 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

static size_t	ft_testoptnstrlen(const unsigned OP_T *uls, const size_t n)
{
	const char *const	c = (const char *)uls;
	size_t				i;

	if (n <= OPT_SIZE)
	{
		i = 0;
		while (i < n)
			if (c[i++] == '\0')
				return (i);
	}
	return (0);
}

size_t			ft_strnlen(const char *str, size_t n)
{
	const char			*s = str;
	const unsigned OP_T *uls;
	unsigned OP_T		x;

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
			if ((x = ft_testoptnstrlen(uls, OPT_SIZE)) != 0)
				return ((const char *)uls - str + x - 1);
		++uls;
		n -= OPT_SIZE;
	}
	x = ft_testoptnstrlen(uls, n);
	if (x != 0 && n > x - 1)
		return ((const char *)uls - str + x - 1);
	return ((const char *)uls - str + n);
}
