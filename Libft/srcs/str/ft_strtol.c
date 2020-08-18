/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 13:54:32 by svet              #+#    #+#             */
/*   Updated: 2020/08/18 12:34:45 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_math.h"
#include <limits.h>
#include <sys/_types/_null.h>

static inline unsigned long	ft_lim(const long sign)
{
	return (sign == -1L ? 1UL - (LONG_MIN + LONG_MAX) + LONG_MAX : LONG_MAX);
}

static inline int			ft_ishex(const char *s, int base)
{
	return ((base == 0 || base == 16) &&
			*s == '0' && (s[1] == 'x' || s[1] == 'X') &&
			((s[2] >= '0' && s[2] <= '9') ||
			(s[2] >= 'A' && s[2] <= 'F') ||
			(s[2] >= 'a' && s[2] <= 'f')));
}

static inline int			ft_parsechr(char c)
{
	if (c >= '0' && c <= '9')
		c -= '0';
	else if (c >= 'A' && c <= 'Z')
		c -= 'A' - 10;
	else if (c >= 'a' && c <= 'z')
		c -= 'a' - 10;
	return (c);
}

static inline int			ft_parsestr(const char *s,
							const long sign, const int base, int *const pany)
{
	register const unsigned long	cutoff = ft_lim(sign) / base;
	register const int				cutlim = ft_lim(sign) % base;
	register char					c;
	register int					any;
	register unsigned long			acc;

	any = 0;
	acc = 0;
	while (ft_isalnum((c = *s++)) != 0)
		if ((c = ft_parsechr(c)) >= base)
			break ;
		else if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
			any = -1;
		else
		{
			any = 1;
			acc = acc * base + c;
		}
	if (any < 0)
		acc = sign == -1L ? LONG_MIN : LONG_MAX;
	else
		acc *= sign;
	*pany = any;
	return (acc);
}

long						ft_strtol(const char *nptr, char **endptr, int base)
{
	const char			*s;
	long				sign;
	int					any;
	unsigned long		acc;

	s = nptr;
	while (ft_isspace((unsigned char)*s) != 0)
		s++;
	sign = *s == '-' || *s == '+' ? ',' - *s++ : 1L;
	if (ft_ishex(s, base))
	{
		s += 2;
		base = 16;
	}
	if (base == 0)
		base = *s++ == '0' ? 8 : 10;
	if (base < 2 || base > 36)
		return (0);
	while (*s == '0')
		s++;
	acc = ft_parsestr(s, sign, base, &any);
	if (endptr != NULL)
		*endptr = (char *)(any ? s + ft_num_of_digs(acc, base) : nptr);
	return (acc);
}
