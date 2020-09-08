/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:21:05 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/01 20:15:43 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

static inline int	ft_testoptstrlen(const unsigned long *uls)
{
	register const size_t	long_size = sizeof(long);
	register const char		*c = (const char *)uls;
	register	size_t		i;

	i = 0;
	while (i < long_size)
	{
		if (c[i] == '\0')
			return ((int)i);
		++i;
	}
	return (-1);
}

size_t				ft_strlen(const char *str)
{
	const char						*s = str;
	register const unsigned long	*uls;
	register int					x;

	x = (int)ft_optmemalign(s);
	while (x-- != 0)
		if (*s++ == '\0')
			return ((size_t)(s - str - 1));
	uls = (const unsigned long *)s;
	while (1)
	{
		if (((*uls - REP_01L) & ((~*uls) & REP_08L)) != 0)
			if ((x = ft_testoptstrlen(uls)) != -1)
				return ((size_t)((const char *)uls - str + x));
		++uls;
	}
}
