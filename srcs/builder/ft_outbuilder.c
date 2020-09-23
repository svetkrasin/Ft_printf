/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuilder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:05:14 by svet              #+#    #+#             */
/*   Updated: 2020/09/23 00:06:23 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/includes/libft.h"
#include "ft_getter.h"
#include "ft_builder.h"
#include <stdlib.h>

int	build_str_error(char *str)
{
	if (str != NULL)
		free(str);
	return (-1);
}

int	build_fmt(t_dlist *out_node, t_fmt *fmt, t_dlist *pos_head, va_list ap)
{
	size_t		n;
	int			ret;
	t_argval	argval;

	n = fmt->width_pos;
	if (n != 0 && (ret = get_width(fmt, n, pos_head, ap)) < 0)
		return (ret);
	n = fmt->prec_pos;
	if (n != 0 && (ret = get_prec(fmt, n, pos_head, ap)) < 0)
		return (ret);
	if ((n = fmt->param) != 0)
		argval = get_pos_value(n, pos_head, ap);
	else
		argval = get_argtype(fmt->type, fmt->flags, ap);
	return (build_out_node(out_node, argval, fmt));
}

int	build_out_node(t_dlist *out, t_argval argval, t_fmt *fmt)
{
	const char		type = fmt->type;

	if (ft_memchr("diuoxbUOXD", type, 10) != NULL)
		return (build_int(out, argval.val_max, *fmt));
	if (type == 's' || type == 'S')
		return (build_str(out, argval.val_ptr_t, *fmt));
	if (type == 'c' || type == 'C')
		return (build_chr(out, argval.val_int, *fmt));
	if (type == 'f' || type == 'F')
		return (build_float(out, argval.val_long_double, *fmt));
	if (type == 'p' || type == 'P')
		return (build_int(out, (uintmax_t)argval.val_ptr_t, *fmt));
	if (type == '%')
		return (build_chr(out, '%', *fmt));
	if (type == 'n')
		return (build_number(out, argval.val_ptr_t, fmt->flags));
	return (build_rand_chr(out, type, fmt));
}

int	build_out_pos(t_dlist *out_node, t_dlist *fmt_node, t_dlist *pos_head,
																	va_list ap)
{
	t_fmt	*tmp_fmt;
	t_dlist	*tmp_node;

	while (out_node != NULL)
	{
		if (out_node->content_size == 0)
		{
			tmp_fmt = fmt_node->content;
			if (build_fmt(out_node, tmp_fmt, pos_head, ap) == -1)
				return (-1);
			tmp_node = fmt_node;
			fmt_node = fmt_node->next;
			ft_dlstdelone(&tmp_node, ft_lstdelcontent);
		}
		out_node = out_node->next;
	}
	ft_dlstdel(&pos_head, ft_lstdelcontent);
	return (0);
}
