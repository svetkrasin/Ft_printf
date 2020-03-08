/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:02:17 by skrasin           #+#    #+#             */
/*   Updated: 2020/03/08 06:07:25 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_prepstruct(t_printf *node, const char *fmt, va_list orarg)
{
	node->save_errno = errno;
	if (fmt == NULL && (errno = EINVAL))
		return (-1);
	node->fmt = fmt;
	va_copy(node->ap_save, orarg);
	node->fstr = NULL;
	node->n = 0;
	node->f = ft_strchrnul(fmt, '%');
	ft_outstring(&(node->fstr), fmt, node->f - (const char *)fmt);
	node->done = ft_check_ret(node->done, node->f - (const char *)fmt);
	return (node->done);
}

void		ft_procf(t_printf *node)
{
	while ((*((node->ch) = ft_strchrnul(node->f, '%')) != '\0' &&
														node->done != -1))
	{
		if (node->ch - 1 - node->f > 0)
			ft_outstring(&(node->fstr), node->f, node->f - node->ch - 1);
		node->f = ++(node->ch);
		ft_parse_param(node);
		ft_parse_flags(node);
		ft_parse_width(node);
		ft_parse_prec(node);
		ft_parse_length(node);
		ft_parse_type(node);
	}
}

int			ft_vasprintf(char **result_ptr, const char *format, va_list args)
{
	t_printf	*node;
	int			ret;

	if (!(node = (t_printf *)ft_memalloc(sizeof(t_printf))) ||
									(ft_prepstruct(node, format, args)) == -1)
		return (-1);
	ft_procf(node);
	*result_ptr = node->fstr;
	ret = node->done;
	free(node);
	return (ret);
}
