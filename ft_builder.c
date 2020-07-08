/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:21:05 by svet              #+#    #+#             */
/*   Updated: 2020/07/07 18:19:55 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_param_value(size_t n, t_list *pos_node, va_list ap)
{
	return (1);
}

int	build_fmt(t_list *out_node, t_list fmt_node, t_list *pos_head, va_list ap)
{
	int		width;
	int		prec;
	size_t	n;

	if ((n = ((t_fmt *)(fmt_node.content))->width_param) != 0)
		width = get_param_value(n , pos_head, ap);
	return (1);
}

int	build_str(t_list *out_node, t_list *fmt_node, t_list *pos_head, va_list ap)
{
	while (out_node != NULL)
	{
		if (out_node->content_size == 0)
		{
			build_fmt(out_node, *fmt_node, pos_head, ap);
			fmt_node = fmt_node->next;
			//delete fmt nodes?
		}
		out_node = out_node->next;
	}
	return (1);
}


// int		ft_str_build(char *str, t_printf *node) // check for '-'??? //return!!! //free up space
// {
// 	size_t	slen;
// 	char	pad; //not needed

// 	str == NULL ? str = "(null)" : 0;
// 	if ((slen  = ft_strlen(str)) > node->precision)
// 		slen = node->precision;
// 	if (node->width > slen && !(node->flags & 16))
// 	{
// 		pad = node->flags & 2 ? '0' : ' ';
// 		ft_strappend(&node->fin_str, ft_memset(ft_strnew(node->width - slen), pad, node->width - slen));
// 		node->width = 0;
// 	}
// 	ft_strappend(&node->fin_str, str);
// 	if (node->width > slen && node->flags & 16)
// 		ft_strappend(&node->fin_str, ft_memset(ft_strnew(node->width - slen), ' ', node->width - slen));
// 	return (1);
// }

// int		ft_int_build(uintmax_t val, int base, t_printf *node, int is_upper) //negative base as lower case //free up space
// {
// 	int	minus;
// 	int	ndigs;
// 	int nchars;

// 	minus = 0;
// 	if ((intmax_t)val < 0)
// 		minus = 1;
// 	ndigs = ft_unum_of_digs(val, base);
// 	if (node->flags & 1 && base == 8)
// 		node->precision < ndigs + 1 ? node->precision = ndigs + 1 : 0;
// 	ndigs < node->precision ? ndigs = node->precision : 0;
// 	nchars = ndigs;
// 	minus == 1 || (node->flags & (4 | 8)) ? ++nchars : 0;
// 	node->flags & 1 && base == 16 ? nchars += 2 : 0;
// 	if (!(node->flags & (2 | 16)) && node->width > nchars)
// 	{
// 		ft_strappend(&node->fin_str, ft_memset(ft_strnew(node->width - nchars), ' ', node->width - nchars));
// 		node->width = nchars;
// 	}
// 	if (minus == 1)
// 		ft_strappend(&node->fin_str, ft_memset(ft_strnew(1), '-', 1));
// 	else if (node->flags & 8)
// 		ft_strappend(&node->fin_str, ft_memset(ft_strnew(1), '+', 1));
// 	else if (node->flags & 4)
// 		ft_strappend(&node->fin_str, ft_memset(ft_strnew(1), ' ', 1));
// 	if ((node->flags & 1) && base == 16) //nested ?
// 		ft_strappend(&node->fin_str, is_upper == 1 ? "0X" : "0x");
// 	if ((node->flags & (2 | 16)) == 2 && node->width > ndigs)
// 	{
// 		ft_strappend(&node->fin_str, ft_memset(ft_strnew(node->width - nchars), '0', node->width - nchars));
// 		node->width = nchars;
// 	}
// 	ft_strappend(&node->fin_str, ft_ltoa_base(val, base, is_upper));
// 	if (node->flags & 16 && node->width > nchars)
// 		ft_strappend(&node->fin_str, ft_memset(ft_strnew(node->width - nchars), ' ', node->width - nchars));
// 	return (1);
// }