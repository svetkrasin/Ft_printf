/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatbuilder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:38:02 by svet              #+#    #+#             */
/*   Updated: 2020/09/22 22:17:45 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builder.h"
#include <stdlib.h>

static inline int	build_float_pow(int pow)
{
	int x;

	x = 1;
	while (pow-- != 0)
		x *= 10;
	return (x);
}

static inline char	*build_ftoa_base(long double val, int prec, int base)
{
	const int		minus = val < 0 ? 1 : 0;
	unsigned long	vd[2];
	char			*str[3];

	++base;
	minus == 1 ? val = -val : 0;
	vd[0] = (unsigned long)(val);
	vd[1] = (unsigned long)((val - vd[0]) * build_float_pow(prec + 1));
	vd[1] % 10 > 4 ? vd[1] += 10 : 0;
	vd[1] /= 10;
	prec < (int)ft_unum_of_digs(vd[1], 10) ? ++vd[0] : 0;
	str[0] = ft_ltoa_base(minus == 1 ? -vd[0] : vd[0], 10, 0);
	str[1] = ft_ultoa_base(vd[1], 10, 0);
	if (str[0] == NULL || str[1] == NULL)
		return (NULL);
	vd[0] = ft_strlen(str[0]);
	if ((str[2] = ft_strnew(vd[0] + prec + 1)) == NULL)
		return (NULL);
	ft_memcpy(str[2], str[0], vd[0]);
	*(str[2] + vd[0]) = '.';
	ft_memcpy(str[2] + vd[0] + 1, str[1], prec);
	free(str[0]);
	free(str[1]);
	return (str[2]);
}

static inline char	*build_float_sep(long double val, t_fmt *f, int base)
{
	const int	isinf = ft_isinf(val);
	const int	isnan = ft_isnan(val);
	char		*str;

	if (isinf != 0 || isnan != 0)
	{
		f->flags &= ~FL_ZEROPAD;
		if (isinf == -1 || isnan == -1)
		{
			if ((str = ft_strnew(4)) == NULL)
				return (NULL);
			if (isinf == -1)
				return (ft_memcpy(str, f->type <= 'G' ? "-INF" : "-inf", 4));
			return (ft_memcpy(str, f->type <= 'G' ? "-NAN" : "-nan", 4));
		}
		else if ((str = ft_strnew(3)) == NULL)
			return (NULL);
		else if (isinf == 1)
			return (ft_memcpy(str, f->type <= 'G' ? "INF" : "inf", 3));
		else
			return (ft_memcpy(str, f->type <= 'G' ? "NAN" : "nan", 3));
	}
	return (build_ftoa_base(val, f->prec_val, base));
}

static inline char	*build_float_str(char *s, char *number, t_fmt f)
{
	if (!(f.flags & FL_LADJUST) && !(f.flags & FL_ZEROPAD))
	{
		s = (char *)((long)ft_memset(s, ' ', f.width_val) + f.width_val);
		f.width_val = 0;
	}
	if (f.flags & FL_SIGN)
		ft_memset(s++, '+', 1);
	else if (f.flags & FL_SPACE)
		ft_memset(s++, ' ', 1);
	s = (char *)((long)ft_memcpy(s, number, f.param) + f.param);
	return (s);
}

int					build_float(t_dlist *o, long double val, t_fmt f)
{
	const int	base = 10;
	char		*s;

	if (f.prec_val < 0)
		f.prec_val = 6;
	s = build_float_sep(val, &f, base);
	if (s == NULL)
		return (-1);
	f.param = ft_strlen(s);
	f.prec_val = ft_max(0, f.prec_val -
					ft_strlen((void *)((long)ft_memchr(s, '.', f.param) + 1)));
	f.type = base == 16 && f.flags & FL_ALT ? 2 : 0;
	f.width_val = ft_max(0, f.width_val - f.param - f.prec_val - f.type);
	if ((o->content = ft_strnew(f.width_val + f.param + f.prec_val + f.type))
																		== NULL)
		return (build_str_error(s));
	f.type = base;
	o->content_size = (long)build_float_str(o->content, s, f);
	free(s);
	return (o->content_size -= (long)o->content);
}
