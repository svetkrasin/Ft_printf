/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:02:17 by skrasin           #+#    #+#             */
/*   Updated: 2020/06/24 14:33:53 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_prepstruct(t_printf *node, const char *fmt, va_list orarg)
{
	ft_memset(node, 0, sizeof(t_printf));
	node->save_errno = errno;
	if (fmt == NULL && (errno = EINVAL))
		return (-1);
	node->ch = NULL;
	va_copy(node->ap_save, orarg);
	node->fmt = ft_strchrnul(fmt, '%');
	if (ft_upd_ret(node, node->fmt - (const char *)fmt) == -1)
		return (-1);
	if ((node->fin_str = ft_strnew(0)) == NULL)
		return (-1);
	ft_strnappend(&node->fin_str, fmt, node->fmt - fmt);
	return (node->done);
}

static int	ft_procfmt(t_printf *node)
{
	while ((*(node->ch = ft_strchrnul(node->fmt, '%')) != '\0' &&
															node->done != -1))
	{
		if (node->ch - node->fmt != 0)
		{
			if (ft_upd_ret(node,  node->ch - node->fmt) == -1)
				return (-1);
			ft_strnappend(&node->fin_str, node->fmt,  node->ch - node->fmt);
		}
		node->fmt = node->ch + 1;
		ft_parse_param(node);
		ft_parse_flags(node);
		ft_parse_width(node);
		ft_parse_prec(node);
		ft_parse_length(node);
		ft_parse_type(node);
	}
	if (node->ch - node->fmt != 0)
	{
		if (ft_upd_ret(node, node->ch  - node->fmt) == -1)
			return (-1);
		ft_strnappend(&node->fin_str, node->fmt,  node->ch - node->fmt);
	}
	return (node->done);
}

int			ft_vasprintf(char **result_ptr, const char *format, va_list args)
{
	t_printf	*node;
	int			ret;

	if (!(node = (t_printf *)ft_memalloc(sizeof(t_printf))) ||
									(ft_prepstruct(node, format, args)) == -1)
		return (-1);
	ft_procfmt(node);
	*result_ptr = node->fin_str;
	ret = node->done;
	free(node);
	return (ret);
}
