/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:40:35 by svet              #+#    #+#             */
/*   Updated: 2020/07/07 18:19:59 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int		printf_type(const char **fmt_p, t_printf *node)
// {
// 	const char type = **fmt_p;

// 	node->fmt = fmt_p + 1;
// 	if (ft_memchr("diuoxXcCsSpPfFeEgGaAmn%", type, 23) == NULL)
// 		return(-1);
// 	if (ft_memchr("diuoxX", type, 6) != NULL && printf_nbr_wrapper(node) == 0)
// 		return (-1);
// 	else if (ft_memchr("cCsS", type, 4) != NULL && printf_str_wrapper(node) == 0)
// 		return (-1);
// 	else if ((type == 'p' || type == 'P') && printf_pointer_wrapper(node) == 0)
// 		return (-1);
// 	else if (ft_memchr("fFeEgGaA", type, 8) != NULL && printf_float_wrapper(node) == 0)
// 		return (-1);
// 	else if (type == 'm' && printf_strerror_wrapper(node) == 0)
// 		return (-1);
// 	else if (type == 'n' && printf_n_wrapper(node) == 0)
// 		return (-1);
// 	else if (type == '%' && printf_percent_wrapper(node) == 0)
// 		return (-1);
// 	// else if (type == 'p')
// 	// 	ft_int_build((unsigned long)va_arg(node->ap_save, void *), 16, node, 0);
// 	// else if (type == 'd' || type == 'i')
// 	// 	ft_int_build(va_arg(node->ap_save, int), 10, node, 0);
// 	return (1);
// }

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

const char			*fmt_flags(const char *format, char *fmt_flags)
{
	const char	*flags = "#0 +-";
	const char	*cur_flag;
	char		c;

	c = *fmt_flags;
	while ((cur_flag = ft_memchr(flags, *format, 6)) != NULL)
	{
		c |= 1 << (cur_flag - flags);
		++format;
	}
	c & FL_PLUS ? c &= ~FL_SPACE : 0;
	*fmt_flags = c & FL_MINUS ? c & ~FL_ZERO : c;
	return (format);
}

static inline int	fmt_width(long n, t_fmt *fmt)
{
	if (fmt_eoverflow(n) == 1)
		return (-2);
	fmt->width_value = n;
	fmt->width_param = 0L;
	return (0);
}


int					fmt_pos(unsigned long n, char type, t_fmt *fmt,
																t_list **pos_p)
{
	t_pos	new_pos;
	t_list	*tmp_node;

	if (n == 0)
		return (0);
	new_pos.n = n;
	new_pos.type = 0;
	fmt->param = n;
	if ((tmp_node = ft_lstnew(&new_pos, sizeof(t_pos))) == NULL)
		return (-1);
	ft_lstadd(pos_p, tmp_node);
	return (1);
}

int					fmt_pos_or_width(const char **format_p, t_fmt *fmt,
																t_list **pos_p)
{
	const char			*format = *format_p;
	const unsigned long	n = ft_strtoul(format, (char **)&format, 10);

	if (*format == '$')
	{
		*format_p = format + 1;
		return (fmt_pos(n, 0, fmt, pos_p) == -1 ? -1 : 0);
	}
	*format_p = format;
	return (fmt_width(n, fmt));
}

int					fmt_aster(const char **format_p, t_fmt *fmt, t_list **pos_p,
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
			fmt->width_value = 0;
			fmt->width_param = n;
			return (fmt_pos(n, 'i', fmt, pos_p));
		}
	}
	ast = va_arg(ap, int);
	if (ast < 0)
	{
		fmt->flags |= FL_MINUS;
		ast = -ast;
	}
	return (fmt_width(ast, fmt));
}
