/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 12:06:13 by svet              #+#    #+#             */
/*   Updated: 2020/09/23 00:43:24 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getter.h"
#include <sys/_types/_null.h>

static inline long double	get_argfloat(int length, va_list ap)
{
	if (length & FL_QUADINT)
		return (va_arg(ap, long double));
	return (va_arg(ap, double));
}

t_argval					get_argtype(char type, int length, va_list ap)
{
	t_argval argval;

	argval.val_long_double = 0.0;
	if (ft_memchr("diuoxbUXOD", type, 10) != NULL)
	{
		if (length & FL_MAXINT)
			argval.val_max = va_arg(ap, uintmax_t);
		else if (length & FL_SIZEINT)
			argval.val_size_t = va_arg(ap, size_t);
		else if (length & FL_PTRDIFF)
			argval.val_ptrdiff_t = va_arg(ap, ptrdiff_t);
		else if (length & FL_QUADINT)
			argval.val_quad = va_arg(ap, unsigned long long int);
		else if (length & FL_LONGINT)
			argval.val_long = va_arg(ap, unsigned long int);
		else
			argval.val_int = va_arg(ap, unsigned int);
	}
	else if (ft_memchr("spSPn", type, 5) != NULL)
		argval.val_ptr_t = va_arg(ap, void *);
	else if (ft_memchr("fFeEgGaA", type, 8) != NULL)
		argval.val_long_double = get_argfloat(length, ap);
	else if (type == 'c' || type == 'C')
		argval.val_int = va_arg(ap, int);
	return (argval);
}

t_argval					get_pos_value(size_t n, t_dlist *pos_node,
																	va_list ap)
{
	va_list		ap_cpy;
	t_argval	n_argval;
	t_pos		*tmp_pos;

	va_copy(ap_cpy, ap);
	while (n-- > 0)
	{
		tmp_pos = pos_node->content;
		n_argval = get_argtype(tmp_pos->type, tmp_pos->flags, ap_cpy);
		pos_node = pos_node->next;
	}
	return (n_argval);
}

int							get_width(t_fmt *fmt, size_t n, t_dlist *pos_node,
																	va_list ap)
{
	int width;

	width = get_pos_value(n, pos_node, ap).val_int;
	if (width < 0)
	{
		fmt_upd_flags(FL_LADJUST, fmt);
		width = -width;
	}
	return (fmt_width(width, fmt));
}

int							get_prec(t_fmt *fmt, size_t n, t_dlist *pos_node,
																	va_list ap)
{
	int prec;

	prec = get_pos_value(n, pos_node, ap).val_int;
	return (prec < 0 ? fmt_set_prec(-1, 0, fmt) : fmt_prec(prec, fmt));
}
