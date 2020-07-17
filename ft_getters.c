/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:47:02 by svet              #+#    #+#             */
/*   Updated: 2020/07/17 12:47:05 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_argint(int length, va_list ap)
{
	if (length & FL_MAXINT)
		return (va_arg(ap, intmax_t));
	else if (length & FL_SIZEINT)
		return (va_arg(ap, size_t));
	else if (length & FL_PTRDIFF)
		return (va_arg(ap, ptrdiff_t));
	else if (length & FL_QUADINT)
		return (va_arg(ap, long long int));
	else if (length & FL_LONGINT)
		return (va_arg(ap, long int));
	return (va_arg(ap, int));
}

double		get_argfloat(int length, va_list ap)
{
	if (length & FL_QUADINT)
		return (va_arg(ap, long double));
	return (va_arg(ap, double));
}

void		*get_argtype(char type, int length, va_list ap) //pointer to stack var? //make func pointers
{
	void 		*p;
	intmax_t	n;
	double		d;

	p = NULL;
	if (ft_memchr("dDiUuoOxXn", type, 10) != NULL)
	{
		n = get_argint(length, ap);
		p = &n;
	}
	else if (ft_memchr("sSpP", type, 4) != NULL)
		p = va_arg(ap, void *);
	else if (ft_memchr("fFeEgGaA", type, 8) != NULL)
	{
		d = get_argfloat(length, ap);
		p = &d;
	}
	else if (ft_memchr("cC", type, 2) != NULL)
	{
		n = va_arg(ap, int);
		p = &n;
	}
	return (p);
}

void	*get_pos_value(size_t n, t_list *pos_node, va_list ap)
{
	va_list ap_cpy;
	void	*p;

	va_copy(ap_cpy, ap);
	p = NULL;
	while(n-- > 0)
	{
		p = get_argtype(((t_pos *)(pos_node->content))->type, ((t_pos *)(pos_node->content))->flags, ap_cpy);
		pos_node = pos_node->next;
	}
	return (p);
}

int		get_width(t_fmt *fmt, size_t n, t_list *pos_node, va_list ap)
{
	int width;

	width = *(int *)get_pos_value(n , pos_node, ap);
	if (width < 0)
	{
		fmt_upd_flags(FL_LADJUST, fmt);
		width = -width;
	}
	return (fmt_width(width, fmt));
}

int		get_prec(t_fmt *fmt, size_t n, t_list *pos_node, va_list ap)
{
	int prec;

	prec = *(int *)get_pos_value(n , pos_node, ap);
	return (prec < 0 ? fmt_set_prec(-1, 0, fmt) : fmt_prec(prec, fmt));
}
