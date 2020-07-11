/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:21:05 by svet              #+#    #+#             */
/*   Updated: 2020/07/11 11:33:20 by svet             ###   ########.fr       */
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

int		build_width(t_fmt *fmt, size_t n, t_list *pos_node, va_list ap)
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

int		build_prec(t_fmt *fmt, size_t n, t_list *pos_node, va_list ap)
{
	int prec;

	prec = *(int *)get_pos_value(n , pos_node, ap);
	return (prec < 0 ? fmt_set_prec(-1, 0, fmt) : fmt_prec(prec, fmt));
}

char	*build_wstr(wchar_t *str)
{
	char	*wstr;
	char	tmp_p;

	if ((wstr = ft_memalloc(sizeof(wchar_t))) == NULL)
		return (NULL);
	while (*str != L'\0')
	{
		if ((tmp_p = ft_tombyte(*str++)) == NULL)
			return (-1);
		ft_strappend(&wstr, tmp_p);
		free(tmp_p);
	}
	return(wstr);
}

char	*build_str_padding(char *out_str, int width, int flags)
{
	if ((out_str = ft_strnew(width)) == NULL)
		return (NULL);
	return (out_str = ft_memset(out_str, flags & FL_ZEROPAD ? '0' : ' ', width));
}

int		build_str(t_list *out_node, void *str, t_fmt *fmt)
{
	char		*out_str;
	size_t		slen;
	int			width;
	const int	prec = fmt->prec_val;
	const int	flags = fmt->flags;

	if (str == NULL)
		str = "(null)";
	else if ((flags & FL_LONGINT || fmt->type == 'S') && (str = build_wstr(str)) == NULL)
		return (-1);
	slen = prec >= 0 ? ft_strnlen(str, prec) : ft_strlen(str);
	width = fmt->width_val - slen;
	out_str = NULL;
	if (width > 0 && !(flags & FL_LADJUST))
		out_str = ft_memset(ft_strnew(width), flags & FL_ZEROPAD ? '0' : ' ', width); //new NULL??
	out_node->content = out_str == NULL ? ft_memcpy(ft_strnew(slen), str, slen) : ft_strnappend(&out_str, str, slen); //new NULL??
	if (width > 0 && flags & FL_LADJUST)
	{
		out_str = ft_memset(ft_strnew(width - slen), ' ', width); //new NULL??
		ft_strnappend((char **)&out_node->content, out_str, width);
		free(out_str);
	}
	out_node->content_size = slen + (width > 0 ? width : 0);
	flags & FL_LONGINT || fmt->type == 'S' ? free(str) : 0;
	return (0);
}

int		build_chr(t_list *out_node, void *c_p, t_fmt *fmt)
{
	char	*cp_to_str;

	if ((fmt->flags & FL_LONGINT || fmt->type == 'C') && (cp_to_str = ft_tombyte(*(wchar_t *)c_p)) == NULL)
		return (-1);
	else if ((cp_to_str = ft_memalloc(2)) == NULL)
		return (-1);
}

int		build_out_str(t_list *out_node, void *p, t_fmt *fmt)
{
	const char type = fmt->type;

	// if (ft_memchr("dDiUuoOxX", type, 9) != NULL)
	// 	build_int(out_node, p, fmt);
	/*else*/ if ((type == 's' || type == 'S') && build_str(out_node, p, fmt) == -1)
		return (-1);
	else if ((type == 'c' || type == 'C') && build_chr(out_node, p, fmt) == -1)
		return (-1);
	// else if (type == 'p' || type == 'P')
	// 	build_pointer(out_node, p, fmt);
	// else if (ft_memchr("fFeEgGaA", type, 8) != NULL)
	// 	build_float(out_node, p, fmt);
	// else if (type == 'm')
	// 	build_message(out_node, p, fmt);
	// else if (type == 'n')
	// 	build_out_nbr(out_node, p, fmt);
	return (1);
}

int		build_fmt(t_list *out_node, t_fmt *fmt, t_list *pos_head, va_list ap)
{
	size_t	n;
	int		ret;
	void	*p;

	p = NULL;
	if ((n = fmt->width_pos) != 0 && (ret = build_width(fmt, n, pos_head, ap)) < 0)
		return (ret);
	if ((n = fmt->prec_pos) != 0 && (ret = build_prec(fmt, n, pos_head, ap)) < 0)
		return (ret);
	if ((n = fmt->param) != 0)
		p = get_pos_value(n , pos_head, ap);
	else
		p = get_argtype(fmt->type, fmt->flags, ap);
	build_out_str(out_node, p, fmt);
	return (0);
}

int		build_out_node(t_list *out_node, t_list *fmt_node, t_list *pos_head, va_list ap)
{
	while (out_node != NULL)
	{
		if (out_node->content_size == 0)
		{
			build_fmt(out_node, fmt_node->content, pos_head, ap);
			fmt_node = fmt_node->next;
			//delete fmt nodes?
		}
		out_node = out_node->next;
	}
	return (1);
}

