/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:12:30 by skrasin           #+#    #+#             */
/*   Updated: 2019/10/08 15:25:09 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	register unsigned char			*ds;
	register const unsigned char	*sr;

	if (!dst && !src)
		return (dst);
	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	while (n--)
		*ds++ = *sr++;
	return (dst);
}
