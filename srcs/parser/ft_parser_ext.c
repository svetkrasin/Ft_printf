/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:56:42 by svet              #+#    #+#             */
/*   Updated: 2020/09/22 22:17:38 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include <limits.h>
#include <errno.h>
#include <sys/_types/_null.h>

int	fmt_eoverflow(long n)
{
	return (n >= INT_MAX || n < 0 ? 1 : 0);
}

int	fmt_prec(long value, t_fmt *fmt)
{
	if (fmt_eoverflow(value) == 1)
	{
		errno = EOVERFLOW;
		return (-1);
	}
	fmt->prec_val = value;
	fmt->prec_pos = 0L;
	return (0);
}

int	fmt_set_prec(int value, unsigned long param, t_fmt *fmt)
{
	fmt->prec_val = value;
	fmt->prec_pos = param;
	return (0);
}

int	fmt_dot(const char **format_p, t_fmt *fmt, t_dlist **pos_p, va_list ap)
{
	int				ast;
	unsigned long	n;
	const char		*format = *format_p;

	if (fmt_set_prec(0, 0, fmt) || ft_isdigit(*++format) == 1)
		return (fmt_prec(ft_strtoul(format, (char **)format_p, 10), fmt));
	if (*format == '*')
	{
		*format_p = ++format;
		if (ft_isdigit(*format) == 1)
		{
			n = ft_strtoul(format, (char **)&format, 10);
			if (*format == '$')
			{
				*format_p = format + 1;
				fmt_set_prec(-1, n, fmt);
				return (fmt_pos(n, 'i', fmt, pos_p));
			}
		}
		else
			return ((ast = va_arg(ap, int)) < 0 ? fmt_set_prec(-1, 0, fmt) :
															fmt_prec(ast, fmt));
	}
	*format_p = format;
	return (0);
}

int	fmt_lenght_and_type(const char **format_p, t_fmt *fmt)
{
	const char	*format = *format_p;
	const char	*lengthes = "hjtzlLq";
	const char	*cur_length;
	int			length;

	length = 0;
	while ((cur_length = ft_memchr(lengthes, *format, 7)) != NULL && ++format)
		if (cur_length - lengthes == 0 && length & FL_SHORTINT)
		{
			length &= ~FL_SHORTINT;
			length |= FL_CHARINT;
		}
		else if (cur_length - lengthes == 2 && length & FL_LONGINT)
			length |= FL_QUADINT;
		else
			length |= FL_SHORTINT << (cur_length - lengthes);
	if (length != 0 && (*format_p = format))
		return (fmt->flags |= length);
	*format_p = *format == '\0' ? format : format + 1;
	fmt_revise_flags(*format, fmt);
	return (1);
}
