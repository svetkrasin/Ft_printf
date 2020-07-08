/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:56:42 by svet              #+#    #+#             */
/*   Updated: 2020/07/07 14:05:15 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			fmt_eoverflow(long n)
{
	return (n >= INT_MAX || n < 0 ? 1 : 0);
}

static inline int	fmt_prec(long n, t_fmt *fmt)
{
	if (fmt_eoverflow(n) == 1)
		return (-2);
	fmt->prec_value = n;
	fmt->prec_param = 0L;
	return (0);
}

static inline int	fmt_set_prec(int value, unsigned long param, t_fmt *fmt)
{
	fmt->prec_value = value;
	fmt->prec_param = param;
	return (0);
}

int					fmt_dot(const char **format_p, t_fmt *fmt, t_list **pos_p,
																	va_list ap)
{
	int				ast;
	unsigned long	n;
	const char		*format = *format_p;

	if (ft_isdigit(*++format) == 1)
		return (fmt_prec(ft_strtoul(format, (char **)format_p, 10), fmt));
	else if (*format == '*')
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
	return (0);
}

int					fmt_lenght_and_type(const char **format_p, t_fmt *fmt)
{
	const char	*format = *format_p;
	char		length;
	char		cur_c;
	char		next_c;

	length = 0;
	cur_c = *format;
	next_c = cur_c != '\0' ? *(format + 1) : '\0';
	if (cur_c == 'h')
		length = next_c == 'h' ? 0x2L : 0x1L;
	else if (cur_c == 'l' || cur_c == 'j' || cur_c == 'z' || cur_c == 't')
		length = next_c == 'l' ? 0x8L : 0x4L;
	else if (cur_c == 'L')
		length = 0x10L;
	if (length != 0)
	{
		fmt->length = length;
		format += 1 + (next_c == 'h' || next_c == 'l' ? 1 : 0);
		cur_c = *format;
	}
	if (ft_memchr("diuoxXcCsSpPfFeEgGaAmn%", cur_c, 23) == NULL)
		return (0);
	fmt->type = cur_c;
	*format_p = format;
	return (1);
}
