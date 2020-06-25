/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:09:29 by skrasin           #+#    #+#             */
/*   Updated: 2020/06/15 20:18:01 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_char.h"
#include <unistd.h>

void				ft_putchar_fd(int c, int fd)
{
	char	buf[6];
	size_t	i;
	size_t	n;
	char	flash;

	if (ft_isascii(c) == 1)
		write(fd, &c, 1);
	else
	{
		i = 5;
		ft_bzero(buf, 6);
		while(c > 0x1F && i > 0)
		{
			buf[i--] = c ^ ((c ^ 0x80) & 0xFFFFFFC0);
			c >>= 6;
		}
		n = 6 - i;
		flash = 7;
		while (n-- > 0)
			buf[i] |= 1 << flash--; //flash 0x10
		buf[i] |= c;
		write(fd, buf + i, 6 - i);
	}
}
