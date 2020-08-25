/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatbuilder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:38:02 by svet              #+#    #+#             */
/*   Updated: 2020/08/24 13:20:11 by svet             ###   ########.fr       */
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

int		build_float(t_list *o, long double val, t_fmt *f)
{
	o = NULL;
	val++;
	f->flags = 0;
	return (1);
	// const int			exception = build_float_exception(o, val, f);
	// const unsigned int	minus = val < 0 ? 1 : 0;
	// const int			width = f->width_val;
	// int					vd[2];
	// char				*p;

	// if (exception != 0)
	// 	return (exception);
	// minus == 1 ? val = -val : 0;
	// vd[1] = f->prec_val;
	// vd[0] = (int)val;
	// vd[1] = (int)((val - (double)vd[0]) *
	// 						build_float_pow(vd[1] == -1 ? 6 : vd[1]));
	// if (vd[1] % 10 > 4)
	// 	vd[1] > 10 ? vd[1] += 10 : ++vd[0];
	// vd[1] /= 10;
	// if ((vd[0] = build_float_str(o, vd, minus, f)) == -1)
	// 	return (-1);
	// if ((p = ft_itoa(vd[1])) == NULL ||
	// 							ft_strappend((char **)&o->content, p) == NULL)
	// 	return (-1); //free(p)
	// o->content_size = ft_strlen(o->content) +
	// 								(width > vd[0] ? width - vd[0] : 0);
	// free(p);
	// return (build_latepadding((char **)&o->content, f->flags, width - vd[0],
	// 																	vd[0]));
}
