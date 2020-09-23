/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:21:08 by svet              #+#    #+#             */
/*   Updated: 2020/09/22 22:20:27 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include <sys/_types/_null.h>
#include <errno.h>

const char	*fmt_flags(const char *format, t_fmt *fmt)
{
	const char	*flags = "#+ 0-\'";
	const char	*cur_flag;
	int			c;

	c = fmt->flags;
	while ((cur_flag = ft_memchr(flags, *format, 6)) != NULL)
	{
		c |= FL_ALT << (cur_flag - flags);
		++format;
	}
	c & FL_SIGN ? c &= ~FL_SPACE : 0;
	fmt_upd_flags(c, fmt);
	return (format);
}

int			fmt_width(long n, t_fmt *fmt)
{
	if (fmt_eoverflow(n) == 1)
	{
		errno = EOVERFLOW;
		return (-1);
	}
	fmt->width_val = n;
	fmt->width_pos = 0L;
	return (0);
}

int			fmt_pos(unsigned long n, char type, t_fmt *fmt, t_dlist **pos_p)
{
	t_pos	new_pos;
	t_dlist	*tmp_node;

	if (n == 0)
		return (0);
	new_pos.n = n;
	new_pos.type = type;
	new_pos.flags = 0;
	if (type == 0)
		fmt->param = n;
	if ((tmp_node = ft_dlstnew(&new_pos, sizeof(t_pos))) == NULL)
		return (-1);
	ft_dlstadd(pos_p, tmp_node);
	return (1);
}

int			fmt_pos_or_width(const char **format_p, t_fmt *fmt, t_dlist **pos_p)
{
	const char			*format = *format_p;
	const unsigned long	n = ft_strtoul(format, (char **)&format, 10);

	if (*format == '$')
	{
		*format_p = format + 1;
		return (fmt_pos(n, 0, fmt, pos_p));
	}
	*format_p = format;
	return (fmt_width(n, fmt));
}

int			fmt_aster(const char **format_p, t_fmt *fmt, t_dlist **pos_p,
																	va_list ap)
{
	int				ast;
	unsigned long	n;
	const char		*format = *format_p;

	if (ft_isdigit(*++format) == 1)
	{
		n = ft_strtoul(format, (char **)&format, 10);
		if (*format == '$')
		{
			*format_p = format + 1;
			fmt->width_val = 0;
			fmt->width_pos = n;
			return (fmt_pos(n, 'i', fmt, pos_p));
		}
		else
			--format;
	}
	ast = va_arg(ap, int);
	if (ast < 0)
	{
		fmt_upd_flags(FL_LADJUST, fmt);
		ast = -ast;
	}
	*format_p = format;
	return (fmt_width(ast, fmt));
}
