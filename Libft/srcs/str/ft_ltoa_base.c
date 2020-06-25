/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 11:05:57 by svet              #+#    #+#             */
/*   Updated: 2020/06/15 20:31:01 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_math.h"
#include <sys/_types/_null.h>

char	*ft_ltoa_base(long n, int base, int isupper)
{
	char		*s;
	size_t		len;
	long		rem;
	const long	sign = n < 0 ? 1L : 0L;
	const char	a = isupper == 1 ? 'A' : 'a';

	len = ft_num_of_digs(n, base) + sign;
	if (base == 0)
		base = 10;
	if (base < 2 || base > 36 || ((s = (char *)ft_memalloc(len + 1)) == NULL))
		return (NULL);
	s[0] = (sign == 1L) ? '-' : '0';
	while (n != 0)
	{
		rem = (n % base ^ -sign) + sign;
		s[--len] = rem > 9 ? rem - 10 + a : rem + '0';
		n /= base;
	}
	return (s);
}
