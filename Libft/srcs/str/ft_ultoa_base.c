/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:07:38 by svet              #+#    #+#             */
/*   Updated: 2020/08/21 12:16:10 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_math.h"
#include <sys/_types/_null.h>

char	*ft_ultoa_base(unsigned long n, int base, int isupper)
{
	register const char		a = isupper ? 'A' : 'a';
	register unsigned long	rem;
	register char			*s;
	register size_t			len;

	len = ft_num_of_digs(n, base);
	if (base == 0)
		base = 10;
	if (base < 2 || base > 36 || ((s = ft_strnew(len)) == NULL))
		return (NULL);
	while (n != 0)
	{
		rem = n % base;
		s[--len] = rem > 9 ? rem - 10 + a : rem + '0';
		n /= base;
	}
	return (s);
}
