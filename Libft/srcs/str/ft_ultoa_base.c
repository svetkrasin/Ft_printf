/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:07:38 by svet              #+#    #+#             */
/*   Updated: 2020/09/09 18:19:08 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_math.h"
#include <sys/_types/_null.h>

char	*ft_ultoa_base(unsigned long n, int base, int isupper)
{
	register const char		a = isupper ? 'A' : 'a';
	register unsigned long	rem;
	register size_t			len;
	register char			*s;

	len = ft_unum_of_digs(n, base);
	if (base == 0)
		base = 10;
	if (base < 2 || base > 36 || ((s = ft_strnew(len)) == NULL))
		return (NULL);
	s[0] = '0';
	while (n != 0)
	{
		rem = n % (unsigned long)base;
		s[--len] = (char)(rem > 9 ? rem - 10 + (const unsigned long)a :
																	rem + '0');
		n /= (unsigned long)base;
	}
	return (s);
}
