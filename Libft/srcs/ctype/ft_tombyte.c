/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tombyte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:27:38 by svet              #+#    #+#             */
/*   Updated: 2020/07/10 21:48:52 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_memory.h"
#include <stdlib.h>

char	*ft_tombyte(wchar_t c)
{
	char	*mbyte;
	char	buf[6];
	size_t	i;
	size_t	n;
	char	flash;

	if (ft_isascii(c) == 1)
		return ((mbyte = ft_memalloc(2)) == NULL ? NULL :
														ft_memset(mbyte, c, 1));
	i = 5;
	ft_bzero(buf, 6);
	while (c > 0x1F && i > 0)
	{
		buf[i--] = c ^ ((c ^ 0x80) & 0xFFFFFFC0);
		c >>= 6;
	}
	n = 6 - i;
	flash = 7;
	while (n-- > 0)
		buf[i] |= 1 << flash--;
	buf[i] |= c;
	return ((mbyte = ft_memalloc(7 - i)) == NULL ? NULL :
											ft_memcpy(mbyte, buf + i, 6 - i));
}
