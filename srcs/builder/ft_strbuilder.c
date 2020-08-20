/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuilder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:35:04 by svet              #+#    #+#             */
/*   Updated: 2020/08/18 17:08:02 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include <stdlib.h>

char				*build_padding(int flags, int n)
{
	char *pad;

	if ((pad = ft_strnew(n)) == NULL)
		return (NULL);
	return (ft_memset(pad, flags & FL_ZEROPAD ? '0' : ' ', n));
}

int					build_latepadding(char **str, int flags, int n, int len)
{
	char *padding_str;
	char *append_res;

	if (flags & FL_LADJUST && n > 0)
	{
		if ((padding_str = build_padding(flags, n)) == NULL)
			return (-1);
		append_res = ft_memappend((void **)str, padding_str, len, n);
		free(padding_str);
		if (append_res == NULL)
			return (-1);
	}
	return (0);
}

static inline char	*build_wstr(wchar_t *str, int flags, char type)
{
	char	*wstr;
	char	*tmp_p;

	if (!(flags & FL_LONGINT) || type == 's')
		return ((char *)str);
	if ((wstr = ft_memalloc(sizeof(char))) == NULL)
		return (NULL);
	while (*str != L'\0')
	{
		if ((tmp_p = ft_tombyte(*str++)) == NULL ||
											ft_strappend(&wstr, tmp_p) == NULL)
			return (NULL);
		free(tmp_p);
	}
	return (wstr);
}

static inline int	build_str_error_with_flags(char *str, char type, int flags)
{
	if (flags & FL_LONGINT || type == 'S' || type == 'c' || type == 'C')
		free(str);
	return (-1);
}
int					build_str(t_list *o, void *s, t_fmt f)
{
	s = s == NULL ? "(null)" : build_wstr(s, f.flags, f.type);
	if (s == NULL)
		return (-1);
	f.param = f.prec_val > 0 ? ft_strnlen(s, f.prec_val) : ft_strlen(s); //>= ?
	f.width_val -= f.param;
	if (!(f.flags & FL_LADJUST) && f.width_val > 0 &&
				(o->content = build_padding(f.flags, f.width_val)) == NULL)
		return (build_str_error_with_flags(s, f.type, f.flags));
	if ((o->content == NULL && (o->content = ft_strnew(0)) == NULL) ||
		ft_memappend(&o->content, s,
		!(f.flags & FL_LADJUST) && f.width_val > 0 ? f.width_val : 0,
		f.param) == NULL)
		return (build_str_error_with_flags(s, f.type, f.flags));
	if (f.flags & FL_LONGINT || f.type == 'S')
		free(s);
	if (build_latepadding((char **)&o->content, f.flags, f.width_val, f.param)
																		== -1)
		return (build_str_error_with_flags(s, f.type, f.flags));
	return (o->content_size = f.param + (f.width_val > 0 ? f.width_val : 0));
}

int					build_chr(t_list *out_node, int c, t_fmt *fmt)
{
	char *c_as_str;

	if (!(fmt->flags & FL_LONGINT) || fmt->type == 'c')
	{
		if ((c_as_str = ft_strnew(1)) == NULL)
			return (-1);
		*c_as_str = c;
	}
	else if ((c_as_str = ft_tombyte((wchar_t)c)) == NULL)
		return (-1);
	build_str(out_node, c_as_str, *fmt);
	free(c_as_str);
	return (0);
}
