/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuilder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:35:04 by svet              #+#    #+#             */
/*   Updated: 2020/08/25 11:18:50 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include <stdlib.h>

static inline char	*build_wstr(wchar_t *str, int flags)
{
	char	*wstr;
	char	*tmp_p;

	if (!(flags & FL_LONGINT))
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

static inline int	build_wstr_free(char *str, int flags)
{
	if (flags & FL_LONGINT)
		free(str);
	return (-1);
}

int					build_str(t_list *o, void *s, t_fmt f)
{
	if ((s = s == NULL ? "(null)" : build_wstr(s, f.flags)) == NULL)
		return (-1);
	f.prec_val = f.prec_val != -1 ? ft_strnlen(s, f.prec_val) : ft_strlen(s);
	f.width_val = ft_max(0, f.width_val - f.prec_val);
	if ((o->content = ft_strnew(f.prec_val + f.width_val)) == NULL)
		return (build_wstr_free(s, f.flags));
	if (!(f.flags & FL_LADJUST))
	{
		ft_memset(o->content, f.flags & FL_ZEROPAD ? '0' : ' ', f.width_val);
		ft_memcpy((char *)((OP_T)o->content + f.width_val), s, f.prec_val);
	}
	else
	{
		ft_memcpy(o->content, s, f.prec_val);
		ft_memset((char *)((OP_T)o->content + f.prec_val), f.flags & FL_ZEROPAD
													? '0' : ' ', f.width_val);
	}
	build_wstr_free(s, f.flags);
	return ((o->content_size = f.prec_val + f.width_val));
}

int					build_chr(t_list *o, int c, t_fmt f)
{
	char	*s;

	f.width_val = ft_max(0, --f.width_val);
	if (!(f.flags & FL_LONGINT))
	{
		if ((o->content = ft_strnew(f.width_val + 1)) == NULL)
			return (-1);
		if (!(f.flags & FL_LADJUST))
		{
			ft_memset(o->content, f.flags & FL_ZEROPAD ? '0' : ' ', f.width_val);
			ft_memset((char *)((OP_T)o->content + f.width_val), c, 1);
		}
		else
		{
			ft_memset(o->content, c, 1);
			ft_memset((char *)((OP_T)o->content + 1), f.flags & FL_ZEROPAD ? '0' : ' ', f.width_val);
		}
		++f.width_val;
	}
	else
	{
		if ((s = ft_tombyte((wchar_t)c)) == NULL)
			return (-1);
		f.flags &= ~FL_LONGINT;
		f.width_val = build_str(o, s, f);
		free(s);
	}
	return ((o->content_size = f.width_val));
}

// if (s == NULL)
// {
// 	if (f.prec_val == -1 || f.prec_val >= (len = (int)sizeof("(null)") - 1))
// 		s = "(null)";
// 	else
// 	{
// 		s = "";
// 		len = 0;
// 	}
// }

