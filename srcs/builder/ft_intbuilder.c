/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intbuilder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 19:19:03 by svet              #+#    #+#             */
/*   Updated: 2020/08/18 18:52:35 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builder.h"
#include <stdlib.h>

int					build_prependchar(char **str_p, char c)
{
	char *str;
	char *c_as_str;

	str = *str_p;
	if ((str == NULL && (str = ft_strnew(0)) == NULL) ||
								(c_as_str = ft_strnew(1)) == NULL)
		return (-1);
	*c_as_str = c;
	if (ft_strnappend(&str, c_as_str, 1) == NULL)
		return (-1);
	free(c_as_str);
	*str_p = str;
	return (0);
}

int					build_intprefix(char **str, int flags, int minus, int base)
{
	if (minus == 1)
		return (build_prependchar(str, '-'));
	if (flags & FL_SIGN)
		return (build_prependchar(str, '+'));
	if (flags & FL_SPACE)
		return (build_prependchar(str, ' '));
	if (flags & FL_ALT && base == 16)
	{
		if (build_prependchar(str, '0') == -1)
			return (-1);
		return (build_prependchar(str, flags & FL_UPPER ? 'X' : 'x'));
	}
	return (0);
}

static inline int	build_base(char type)
{
	if (type == 'd' || type == 'i' || type == 'u' || type == 'U' || type == 'D')
		return (10);
	if (type == 'p' || type == 'x' || type == 'X' || type == 'P')
		return (16);
	else
		return (8);
}

static inline int	build_ndigits(uintmax_t val, int base, int flags, int prec)
{
	int ndigits;

	ndigits = ft_unum_of_digs(val, base);
	if (flags & FL_ALT && base == 8 && prec < ndigits + 1)
		prec = ndigits + 1;
	if (ndigits < prec)
		ndigits = prec;
	return (ndigits);
}

static inline int	build_nchars(int ndigits, int minus, int flags, int base)
{
	int nchars;

	nchars = ndigits;
	if (minus == 1 || (flags & (FL_SIGN | FL_SPACE)))
		++nchars;
	if ((flags & FL_ALT) && base == 16)
		nchars += 2;
	return (nchars);
}

int					build_int(t_list *o, uintmax_t v, t_fmt f)
{
	const int	minus = f.flags & FL_SIGNED && (intmax_t)v < 0 ? 1 : 0;
	const int	base = build_base(f.type);
	const int	nd = build_ndigits(v, base, f.flags, f.prec_val);
	const int	nc = build_nchars(nd, minus, f.flags, base);
	char		*p;

	minus == 1 ? v = (uintmax_t)(-(intmax_t)v) : 0;
	if (!(f.flags & (FL_LADJUST | FL_ZEROPAD)) && f.width_val > nc &&
			(o->content = build_padding(f.flags, f.width_val - nc)) == NULL)
		return (-1);
	if (build_intprefix((char **)&o->content, f.flags, minus, base) == -1)
		return (-1);
	if ((f.flags & (FL_LADJUST | FL_ZEROPAD)) == FL_ZEROPAD &&
			f.width_val > nd &&
			(o->content = build_padding(f.flags, f.width_val - nc)) == NULL)
		return (-1);
	if (o->content == NULL && (o->content = ft_strnew(0)) == NULL)
		return (-1);
	if ((p = ft_ltoa_base(v, base, (f.flags & FL_UPPER) > 0 ? 1 : 0)) == NULL ||
								ft_strappend((char **)&o->content, p) == NULL)
		return (build_str_error(p));
	o->content_size = nc + (f.width_val > nc ? f.width_val - nc : 0);
	free(p);
	return (build_latepadding((char **)&o->content, f.flags, f.width_val - nc,
																		nc));
}
