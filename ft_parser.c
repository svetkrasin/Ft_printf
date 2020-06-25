/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:40:35 by svet              #+#    #+#             */
/*   Updated: 2020/06/24 17:25:54 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_type(t_printf *node)
{
	const char type = *node->fmt++;

	if (type == 's')
		ft_str_build(va_arg(node->ap_save, char *), node);
	else if (type == 'c')
		ft_str_build(ft_memset(ft_strnew(1), va_arg(node->ap_save, int), 1), node);
	else if (type == 'p')
		ft_int_build((unsigned long)va_arg(node->ap_save, void *), 16, node, 0);
	else if (type == 'd' || type == 'i')
		ft_int_build(va_arg(node->ap_save, int), 10, node, 0);
	return (1);
}

// int		ft_parse_type(t_printf *node)
// {
// 	char c;
// 	if (*node->fmt == 's')
// 	{
// 		ft_strappend(&node->fin_str, va_arg(node->ap_save, char *));
// 		node->fmt++;
// 		if ((node->done =
// 				ft_check_ret(node->done, ft_strlen(node->fin_str + node->done))) == -1)
// 			return (-1);
// 	}
// 	else if (*node->fmt == 'd' || *node->fmt == 'i')
// 	{
// 		ft_strappend(&node->fin_str, ft_itoa(va_arg(node->ap_save, int)));
// 		node->fmt++;
// 		if ((node->done =
// 				ft_check_ret(node->done, ft_strlen(node->fin_str + node->done))) == -1)
// 			return (-1);
// 	}
// 	else if (*node->fmt == 'c')
// 	{
// 		c = va_arg(node->ap_save, int);
// 		ft_strappend(&node->fin_str, ft_memcpy(ft_strnew(2), &c, 1));
// 		node->fmt++;
// 		if ((node->done =
// 				ft_check_ret(node->done, ft_strlen(node->fin_str + node->done))) == -1)
// 			return (-1);
// 	}
// 	else if (*node->fmt == 'p')
// 	{
// 		ft_strappend(&node->fin_str, ft_ultoa_base((unsigned long)va_arg(node->ap_save, void *), 16, 0));
// 		node->fmt++;
// 		if ((node->done =
// 				ft_check_ret(node->done, ft_strlen(node->fin_str + node->done))) == -1)
// 			return (-1);
// 	}
// 	else if (*node->fmt == 'u')
// 	{
// 		ft_strappend(&node->fin_str, ft_ltoa_base((unsigned int)va_arg(node->ap_save, int), 10, 0));
// 		node->fmt++;
// 		if ((node->done =
// 				ft_check_ret(node->done, ft_strlen(node->fin_str + node->done))) == -1)
// 			return (-1);
// 	}
// 	else if (*node->fmt == 'x')
// 	{
// 		ft_strappend(&node->fin_str, ft_ltoa_base((unsigned int)va_arg(node->ap_save, int), 16, 0));
// 		node->fmt++;
// 		if ((node->done =
// 				ft_check_ret(node->done, ft_strlen(node->fin_str + node->done))) == -1)
// 			return (-1);
// 	}
// 	else if (*node->fmt == 'X')
// 	{
// 		ft_strappend(&node->fin_str, ft_ltoa_base((unsigned int)va_arg(node->ap_save, int), 16, 1));
// 		node->fmt++;
// 		if ((node->done =
// 				ft_check_ret(node->done, ft_strlen(node->fin_str + node->done))) == -1)
// 			return (-1);
// 	}
// 	return (node->done);
// }

void		ft_parse_param(t_printf *node) //return ?
{
	const unsigned long	n = ft_strtol(node->fmt, (char **)&node->fmt, 10); //make it unsigned
	size_t				len = ft_unum_of_digs(n, 10);

	if (n != 0)
	{
		if (*node->fmt == '$')
		{
			node->parametr = n;
			++node->fmt;
		}
		else //subject to improve
		{
			ft_parse_flags(node);
			ft_parse_width(node);
		}
	}
}

void		ft_parse_length(t_printf *node) //while ?
{
	const char		cur_c = *node->fmt;
	const char		next_c = cur_c != '\0' ? *(node->fmt + 1) : '\0';

	if (cur_c == 'h')
		node->lenght |= next_c == 'h' ? 2 : 1;
	else if (cur_c == 'l' || cur_c == 'j' || cur_c == 'z' || cur_c == 't')
		node->lenght |= next_c == 'l' ? 8 : 4;
	else if (cur_c == 'L')
		node->lenght |= 16;
	if (node->lenght != 0)
		node->fmt += 1 + (next_c == 'h' || next_c == 'l' ? 1 : 0);
}

void		ft_parse_flags(t_printf *node)
{
	const char	*flags = "#0 +-*";
	const char	*flag;
	char		c;
	long		n;

	c = node->flags;
	while ((flag = ft_memchr(flags, *node->fmt, 6)) != NULL && ++node->fmt)
		c |= 1 << (flag - flags);
	c & 8 ? c &= 4 : 0;
	c & 16 && !(c & 32) ? c &= ~2 : 0;
	if (c & 64)
	{
		c &= ~64;
		if ((n = va_arg(node->ap_save, long)) < 0L)
		{
			c |= 16;
			node->width = -n;
		}
		else
		{
			c &= 16;
			node->width = n;
		}
	}
	node->flags = c;
}

void		ft_parse_width(t_printf *node) //positional n$??
{
	unsigned long n;

	if (node->width == 0)
	{
		n = ft_strtol(node->fmt, (char **)&(node->fmt), 10);
		node->width = n;
	}
}

void		ft_parse_prec(t_printf *node)
{
	long 				n;
	const unsigned long	w_cpy = node->width;

	if (*node->fmt == '.')
	{
		++node->fmt;
		node->width = 0;
		ft_parse_flags(node);
		ft_parse_width(node);
		node->precision = node->width;
		node->width = w_cpy;
		// (p->f & F_PLUS) ? p->f &= ~F_SPACE : 0;
	}
}