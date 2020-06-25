/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:45:03 by skrasin           #+#    #+#             */
/*   Updated: 2020/06/08 17:27:16 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <sys/_types/_null.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*p;

	p = ft_memchr(src, c, n);
	if (p)
		return (ft_mempcpy(dst, src, (size_t)((OP_T)p - (OP_T)src + 1)));
	ft_memcpy(dst, src, n);
	return (NULL);
}
