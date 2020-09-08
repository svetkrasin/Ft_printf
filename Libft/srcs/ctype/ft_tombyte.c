/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tombyte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:27:38 by svet              #+#    #+#             */
/*   Updated: 2020/09/01 17:55:25 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_memory.h"
#include <stdlib.h>

char	*ft_tombyte(wchar_t wc)
{
	register char	*mbyte;
	register char	buf[6];
	register size_t	i;
	register size_t	n;
	register char	flash;

	if (ft_isascii(wc) == 1)
		return ((mbyte = ft_memalloc(2)) == NULL ? NULL :
													ft_memset(mbyte, wc, 1));
		i = 5;
	ft_bzero(buf, 6);
	n = (size_t)wc;
	while (n > 0x1F && i > 0)
	{
		buf[i--] = (char)(n ^ ((n ^ 0x80) & 0xFFFFFFC0));
		n >>= 6;
	}
	wc = (wchar_t)n;
	n = 6 - i;
	flash = 7;
	while (n-- > 0)
		buf[i] |= 1 << flash--;
	buf[i] |= wc;
	return ((mbyte = ft_memalloc(7 - i)) == NULL ? NULL :
											ft_memcpy(mbyte, buf + i, 6 - i));
}
