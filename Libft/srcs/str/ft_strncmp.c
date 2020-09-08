/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:53:45 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/01 19:29:14 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static inline int		ft_4strncmp(const char *s1, const char *s2, size_t n4)
{
	register unsigned char	c1;
	register unsigned char	c2;

	while (n4-- > 0)
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 == '\0' || c1 != c2)
			return (c1 - c2);
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 == '\0' || c1 != c2)
			return (c1 - c2);
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 == '\0' || c1 != c2)
			return (c1 - c2);
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 == '\0' || c1 != c2)
			return (c1 - c2);
	}
	return (0);
}

static inline int		ft_1strncmp(const char *s1, const char *s2, size_t n)
{
	register unsigned char c1;
	register unsigned char c2;

	while (n-- > 0)
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 == '\0' || c1 != c2)
			return (c1 - c2);
	}
	return (0);
}

int						ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	n4;
	int		diff;

	n4 = n >> 2;
	if (n4 != 0)
	{
		if ((diff = ft_4strncmp(s1, s2, n4)) == 0)
		{
			n4 <<= 2;
			return (ft_1strncmp(s1 + n4, s2 + n4, n & 7));
		}
		return (diff);
	}
	return (ft_1strncmp(s1, s2, n));
}
