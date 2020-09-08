/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:09:29 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/01 20:00:23 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_memory.h"
#include "ft_io.h"
#include <unistd.h>

void	ft_putchar_fd(wchar_t c, int fd)
{
	char			buf[6];
	size_t			i;
	size_t			n;
	char			flash;
	unsigned int	wc;

	if (ft_isascii(c) == 1)
		write(fd, &c, 1);
	else
	{
		wc = (unsigned int)c;
		i = 5;
		ft_bzero(buf, 6);
		while (wc > 0x1F && i > 0)
		{
			buf[i--] = (char)(wc ^ ((wc ^ 0x80) & 0xFFFFFFC0));
			wc >>= 6;
		}
		n = 6 - i;
		flash = 7;
		while (n-- > 0)
			buf[i] |= 1 << flash--;
		buf[i] |= wc;
		write(fd, buf + i, 6 - i);
	}
}
