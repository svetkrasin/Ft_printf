/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:56:31 by skrasin           #+#    #+#             */
/*   Updated: 2020/07/11 11:36:05 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_unum_of_digs(unsigned long n, int base)
{
	size_t l;

	l = n == 0 ? 1 : 0;
	while (n != 0)
	{
		n /= base;
		++l;
	}
	return (l);
}

char	*ft_ultoa_base(unsigned long n, int base, int isupper)
{
	char		*s;
	size_t		len;
	long		rem;
	const char	a = isupper == 1 ? 'A' : 'a';

	len = ft_unum_of_digs(n, base);
	len += base == 8 ? 1 : 0;
	len += base == 16 ? 2 : 0;
	if (base < 2 || base > 36 || ((s = (char *)ft_memalloc(len + 1)) == NULL))
		return (NULL);
	if (base == 16 && n == 0)
		return (ft_memcpy(s, "0x0", 4));
	s[0] = '0';
	while (n != 0)
	{
		rem = n % base;
		s[--len] = rem > 9 ? rem - 10 + a : rem + '0';
		n /= base;
	}
	if (base == 16)
		s[--len] = 'x';
	if (base == 16 || base == 8)
		s[len - 1] = '0';
	return (s);
}

unsigned long	ft_strtoul(const char *nptr, char **endptr, int base)
{
	return (ft_strtol(nptr, endptr, base));
}

size_t			ft_lst_length(t_list *head)
{
	size_t	n;

	n = 0;
	while (head != NULL)
	{
		++n;
		head = head->next;
	}
	return (n);
}
