/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:21:05 by skrasin           #+#    #+#             */
/*   Updated: 2020/07/10 14:51:45 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

static inline  int	ft_testoptstrlen(const unsigned OP_T *uls)
{
	register const char				*c = (const char *)uls;
	register	size_t				i;
	register const unsigned OP_T	size = OPT_SIZE;

	i = 0;
	while (i < size)
	{
		if (c[i] == '\0')
			return (i);
		++i;
	}
	return (-1);
}

size_t				ft_strlen(const char *str)
{
	const char						*s = str;
	register const unsigned OP_T	*uls;
	register int					x;

	x = ft_optmemalign(s);
	while (x-- != 0)
		if (*s++ == '\0')
			return (s - str - 1);
	uls = (unsigned OP_T *)s;
	while (1)
	{
		if (((*uls - REP_01L) & ((~*uls) & REP_08L)) != 0)
			if ((x = ft_testoptstrlen(uls)) != -1)
				return ((const char *)uls - str + x);
		++uls;
	}
	return (0);
}
