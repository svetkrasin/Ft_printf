/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:52:33 by svet              #+#    #+#             */
/*   Updated: 2020/07/17 19:16:11 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_io.h"
#include <sys/_types/_size_t.h>

void	ft_putlnbr_base_fd(long n, int base, int isupper, int fd)
{
	register const char	a = isupper == 1 ? 'A' : 'a';
	register const long	sign = n < 0 ? 1L : 0L;
	register long		rem;
	register char		s[22];
	register size_t		len;

	if (base == 0)
		base = 10;
	if (base < 2 || base > 36)
	{
		ft_putchar_fd('\0', fd);
		return ;
	}
	len = ft_num_of_digs(n, base) + sign;
	s[0] = (sign == 1L) ? '-' : '0';
	s[len] = '\0';
	while (n != 0)
	{
		rem = (n % base ^ -sign) + sign;
		s[--len] = rem > 9 ? rem - 10 + a : rem + '0';
		n /= base;
	}
	ft_putstr_fd(s, fd);
}
