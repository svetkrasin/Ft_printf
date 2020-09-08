/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatbuilder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:38:02 by svet              #+#    #+#             */
/*   Updated: 2020/09/07 19:23:57 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builder.h"
#include <stdlib.h>

// static inline int	build_float_exception(t_list *o, long double v, t_fmt *f)
// {
// 	const int isinf = ft_isinf(v);
// 	const int isnan = ft_isnan(v);

// 	if (isinf != 0)
// 	{
// 		f->flags &= ~FL_ZEROPAD;
// 		if (isinf == 1)
// 			return (build_str(o, f->type <= 'G' ? "INF" : "inf", *f));
// 		return (build_str(o, f->type <= 'G' ? "-INF" : "-inf", *f));
// 	}
// 	if (isnan != 0)
// 	{
// 		f->flags &= ~FL_ZEROPAD;
// 		if (isnan == 1)
// 			return (build_str(o, f->type <= 'G' ? "NAN" : "nan", *f));
// 		return (build_str(o, f->type <= 'G' ? "-NAN" : "-NAN", *f));
// 	}
// 	return (0);
// }

// static inline int	build_float_pow(int pow)
// {
// 	int x;

// 	x = 10;
// 	while (pow != 0)
// 		x *= 10;
// 	return (x);
// }

// static inline int	build_float_str(t_list *o, int vparts[2], int minus,
// 																	t_fmt *f)
// {
// 	const int	flags = f->flags;
// 	const int	width = f->width_val;
// 	const int	len = ft_num_of_digs(vparts[0], 10) +
// 							ft_num_of_digs(vparts[1], 10) + minus == 1 ? 2 : 1;
// 	char		*p;

// 	if (!(flags & (FL_LADJUST | FL_ZEROPAD)) && width > len &&
// 					(o->content = build_padding(flags, width - len)) == NULL)
// 		return (-1);
// 	if (build_intprefix((char **)&o->content, flags, minus, 10) == -1)
// 		return (-1);
// 	if ((flags & (FL_LADJUST & FL_ZEROPAD)) == FL_ZEROPAD && width >
// 		len - minus && (o->content = build_padding(flags, width - len)) == NULL)
// 		return (-1);
// 	if (o->content == NULL && (o->content = ft_strnew(0)) == NULL)
// 		return (-1);
// 	if ((p = ft_itoa(vparts[0])) == NULL ||
// 								ft_strappend((char **)&o->content, p) == NULL)
// 		return (build_str_error(p));
// 	if (build_prependchar((char **)&o->content, '.') == -1)
// 		return (build_str_error(p));
// 	free(p);
// 	return (len);
// }

// int		build_float(t_list *o, long double val, t_fmt *f)
// {
// 	const int			exception = build_float_exception(o, val, f);
// 	const unsigned int	minus = val < 0 ? 1 : 0;
// 	const int			width = f->width_val;
// 	int					vd[2];
// 	char				*p;

// 	if (exception != 0)
// 		return (exception);
// 	minus == 1 ? val = -val : 0;
// 	vd[1] = f->prec_val;
// 	vd[0] = (int)val;
// 	vd[1] = (int)((val - (double)vd[0]) *
// 							build_float_pow(vd[1] == -1 ? 6 : vd[1]));
// 	if (vd[1] % 10 > 4)
// 		vd[1] > 10 ? vd[1] += 10 : ++vd[0];
// 	vd[1] /= 10;
// 	if ((vd[0] = build_float_str(o, vd, minus, f)) == -1)
// 		return (-1);
// 	if ((p = ft_itoa(vd[1])) == NULL ||
// 								ft_strappend((char **)&o->content, p) == NULL)
// 		return (-1); //free(p)
// 	o->content_size = ft_strlen(o->content) +
// 									(width > vd[0] ? width - vd[0] : 0);
// 	free(p);
// 	return (build_latepadding((char **)&o->content, f->flags, width - vd[0],
// 																		vd[0]));
// }

static inline int	build_float_pow(int pow)
{
	int x;

	x = 1;
	while (pow-- != 0)
		x *= 10;
	return (x);
}

char	*build_ftoa_base(long double val, int prec, int base)
{
	const int		minus = val < 0 ? 1 : 0;
	unsigned int	vd[2];
	char			*str[3];

	++base;
	minus == 1 ? val -= val : 0;
	vd[0] = (int)(val);
	vd[1] = (unsigned int)((val - vd[0]) * build_float_pow(prec + 1));
	vd[1] % 10 > 4 ? vd[1] += 10 : 0;
	vd[1] /= 10;
	prec < (int)ft_unum_of_digs(vd[1], 10) ? ++vd[0] : 0;
	str[0] = ft_itoa(vd[0]);
	str[1] = ft_itoa(vd[1]);
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

char	*build_float_sep(long double val, t_fmt *f, int base)
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

char *build_float_str(char *s, char *number, t_fmt f)
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

int build_base(int type)
{
	++type;
	return (10);
}

int		build_float(t_list *o, long double val, t_fmt f)
{
	const int	base = build_base(f.type);
	char 		*s;

	if (f.prec_val < 0)
		f.prec_val = 6;
	s = build_float_sep(val, &f, base);
	if (s == NULL)
		return (-1);
	f.param = ft_strlen(s);
	f.prec_val = ft_max(0, f.prec_val - ft_strlen((void *)((long)ft_memchr(s, '.', f.param) + 1)));
	f.type = base == 16 && f.flags & FL_ALT ? 2 : 0;
	f.width_val = ft_max(0, f.width_val - f.param - f.prec_val - f.type);
	if ((o->content = ft_strnew(f.width_val + f.param + f.prec_val + f.type)) == NULL)
		return (build_str_error(s));
	f.type = base;
	o->content_size = (long)build_float_str(o->content, s, f);
	free(s);
	return (o->content_size -= (long)o->content);
}
