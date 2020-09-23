/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 12:38:37 by svet              #+#    #+#             */
/*   Updated: 2020/09/22 22:22:38 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_parser.h>
#include "ft_builder.h"
#include "limits.h"
#include "errno.h"
#include <sys/_types/_null.h>
#include <sys/_types/_ptrdiff_t.h>

static inline ptrdiff_t	fmt_parser(
	t_fmt *fmt,
	const char *format,
	t_dlist **pos_p,
	va_list ap
)
{
	const char	*format_cpy = format;

	while (1)
		if (ft_memchr("#0 +-\'", *format, 6) != NULL)
			format = fmt_flags(format, fmt);
		else if (ft_isdigit(*format) == 1)
		{
			if (fmt_pos_or_width(&format, fmt, pos_p) == -1)
				return (-1);
		}
		else if (*format == '*')
		{
			if (fmt_aster(&format, fmt, pos_p, ap) == -1)
				return (-1);
		}
		else if (*format == '.')
		{
			if (fmt_dot(&format, fmt, pos_p, ap) == -1)
				return (-1);
		}
		else if (fmt_lenght_and_type(&format, fmt) == 1)
			return (format - format_cpy);
}

static inline t_fmt		*fmt_init(void)
{
	t_fmt	*tmp_fmt;

	if ((tmp_fmt = (t_fmt *)ft_memalloc(sizeof(t_fmt))) == NULL)
		return (NULL);
	tmp_fmt->prec_val = -1;
	return (tmp_fmt);
}

static inline int		fmt_as_str(
	const char *format,
	ptrdiff_t m,
	t_dlist **out_p
)
{
	t_dlist	*tmp_node;

	if (m > INT_MAX)
	{
		errno = EOVERFLOW;
		return (-1);
	}
	if ((tmp_node = ft_dlstnew(format, m)) == NULL)
		return (-1);
	ft_dlstadd(out_p, tmp_node);
	return (0);
}

static inline int		fmt_wrap_out_node(
	t_dlist *heads[3],
	t_fmt *fmt,
	va_list ap
)
{
	t_dlist	*tmp_node;

	if ((tmp_node = ft_dlstnew(NULL, 0)) == NULL)
		return (-1);
	ft_dlstadd(&heads[0], tmp_node);
	if (fmt->param == 0 && fmt->prec_pos == 0 && fmt->width_pos == 0)
		return (build_out_node(heads[0], get_argtype(fmt->type, fmt->flags, ap),
																		fmt));
		if ((tmp_node = ft_dlstnew(fmt, sizeof(t_fmt))) == NULL)
		return (-1);
	ft_dlstadd(&heads[1], tmp_node);
	return (0);
}

int						fmt_proc(
	t_dlist *heads[3],
	const char *format,
	va_list ap
)
{
	const char	*ch_p;
	t_fmt		*tmp_fmt;
	ptrdiff_t	m;

	while ((ch_p = ft_strchrnul(format, '%')))
	{
		if ((m = ch_p - format) > 0 && fmt_as_str(format, m, &heads[0]) == -1)
			return (-1);
		if (*ch_p == '\0' || *++ch_p == '\0')
			return (0);
		if ((tmp_fmt = fmt_init()) == NULL)
			return (-1);
		if ((m = fmt_parser(tmp_fmt, ch_p, &heads[2], ap)) == -1)
			return (-1);
		format = ch_p + m;
		if (fmt_wrap_out_node(heads, tmp_fmt, ap) == -1)
			return (-1);
		ft_memdel((void **)&tmp_fmt);
	}
	return (0);
}
