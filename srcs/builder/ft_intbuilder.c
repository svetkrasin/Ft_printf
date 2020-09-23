/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intbuilder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 19:19:03 by svet              #+#    #+#             */
/*   Updated: 2020/09/23 00:07:12 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builder.h"
#include <stdlib.h>

static inline int	build_base(char type)
{
	if (type == 'd' || type == 'i' || type == 'u' || type == 'U' || type == 'D')
		return (10);
	if (type == 'x' || type == 'X')
		return (16);
	if (type == 'p' || type == 'P')
		return (17);
	if (type == 'o' || type == 'O')
		return (8);
	return (2);
}

static inline char	*build_int_str(char *s, char *number, intmax_t v, t_fmt f)
{
	if (!(f.flags & FL_LADJUST) && !(f.flags & FL_ZEROPAD))
	{
		s = (char *)((long)ft_memset(s, ' ', f.width_val) + f.width_val);
		f.width_val = 0;
	}
	if (f.flags & FL_MINUS)
		ft_memset(s++, '-', 1);
	else if (f.flags & FL_SIGN)
		ft_memset(s++, '+', 1);
	else if (f.flags & FL_SPACE)
		ft_memset(s++, ' ', 1);
	if (f.type == 8 && f.flags & FL_ALT && v != 0 && f.prec_val <= (int)f.param)
		ft_memset(s++, '0', 1);
	else if ((f.type == 16 && f.flags & FL_ALT && v != 0) || f.type == 17)
		s = (char *)((long)ft_memcpy(s, f.flags & FL_UPPER ? "0X" : "0x", 2) +
																			2);
	if ((f.flags & FL_LADJUST && f.flags & FL_ZEROPAD) ||
														!(f.flags & FL_LADJUST))
		f.prec_val += f.width_val;
	if (f.prec_val > 0)
		s = (char *)((long)ft_memset(s, '0', f.prec_val) + f.prec_val);
	s = (char *)((long)ft_memcpy(s, number, f.param) + f.param);
	if (f.flags & FL_LADJUST)
		s = (char *)((long)ft_memset(s, ' ', f.width_val) + f.width_val);
	return (s);
}

static inline void	build_int_resolve_minus(uintmax_t *v_p, int *flags_p)
{
	uintmax_t	v;
	int			flags;

	v = *v_p;
	if ((flags = *flags_p) >= FL_MAXINT)
		(intmax_t)v < 0 && flags & FL_SIGNED && (flags |= FL_MINUS) ?
												v = (uintmax_t)(intmax_t)-v : 0;
	else if (flags & FL_SHORTINT)
	{
		if ((short)(v = (unsigned short)(short)v) < 0 && flags & FL_SIGNED
														&& (flags |= FL_MINUS))
			v = (unsigned short)-(short)v;
	}
	else if (flags & FL_CHARINT)
	{
		if ((char)(v = (unsigned char)(char)v) < 0 && flags & FL_SIGNED &&
															(flags |= FL_MINUS))
			v = (unsigned char)-(char)v;
	}
	else if (flags < FL_CHARINT)
		if ((int)(v = (unsigned int)(int)v) < 0 && flags & FL_SIGNED &&
															(flags |= FL_MINUS))
			v = (unsigned int)-(int)v;
	*v_p = v;
	*flags_p = flags;
}

static inline char	*build_int_sep(uintmax_t v, int *flags, int base)
{
	build_int_resolve_minus(&v, flags);
	return (ft_ultoa_base(v, base == 17 ? 16 : base, *flags & FL_UPPER));
}

int					build_int(t_dlist *o, uintmax_t v, t_fmt f)
{
	const int	base = build_base(f.type);
	char		*s;

	f.prec_val < 0 ? f.prec_val = 1 : (f.flags &= ~FL_ZEROPAD);
	if (f.prec_val == 0 && v == 0)
		s = base == 8 && f.flags & FL_ALT ? ft_itoa(0) : ft_strnew(0);
	else
		s = build_int_sep(v, &f.flags, base);
	if (s == NULL)
		return (-1);
	f.param = ft_strlen(s);
	f.prec_val = ft_max(0, f.prec_val - f.param);
	f.type = base == 8 && f.flags & FL_ALT && v != 0 &&
													f.prec_val <= (int)f.param;
	f.type += (base == 16 && f.flags & FL_ALT && v != 0) || base == 17 ? 2 : 0;
	f.type += f.flags & FL_MINUS || f.flags & FL_SIGN || f.flags & FL_SPACE;
	f.width_val = ft_max(0, f.width_val - f.param - f.prec_val - f.type);
	if ((o->content = ft_strnew(f.width_val + f.param + f.prec_val + f.type))
																		== NULL)
		return (build_str_error(s));
	f.type = base;
	o->content_size = (long)build_int_str(o->content, s, v, f);
	free(s);
	return (o->content_size -= (long)o->content);
}
