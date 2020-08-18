/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:05:57 by svet              #+#    #+#             */
/*   Updated: 2020/08/18 10:20:19 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builder.h"
#include "ft_processor.h"
#include "limits.h"
#include <sys/_types/_null.h>
#include <sys/_types/_ptrdiff_t.h>

static inline ptrdiff_t	fmt_parser(t_fmt *fmt, const char *format,
													t_list **pos_p, va_list ap)
{
	const char	*format_cpy = format;
	int			ret;

	while (1)
		if (ft_memchr("#0 +-", *format, 6) != NULL)
			format = fmt_flags(format, fmt);
		else if (ft_isdigit(*format) == 1)
		{
			if ((ret = fmt_pos_or_width(&format, fmt, pos_p)) < 0)
				return (ret);
		}
		else if (*format == '*')
		{
			if ((ret = fmt_aster(&format, fmt, pos_p, ap)) < 0)
				return (ret);
		}
		else if (*format == '.')
		{
			if ((ret = fmt_dot(&format, fmt, pos_p, ap)) < 0)
				return (ret);
		}
		else if (fmt_lenght_and_type(&format, fmt) == 1)
			return (format - format_cpy);
		else
			return (0);
}

static inline int		fmt_as_str(const char *format, ptrdiff_t m,
																t_list **out_p)
{
	t_list	*tmp_node;

	if (m > INT_MAX)
		return (-2);
	if (m > 0) //necessary?
	{
		if ((tmp_node = ft_lstnew(format, m)) == NULL)
			return (-1);
		ft_lstadd(out_p, tmp_node);
	}
	return (0);
}

static inline int		fmt_prep(t_fmt **fmt_p)
{
	t_fmt	*tmp_fmt;

	if ((tmp_fmt = (t_fmt *)ft_memalloc(sizeof(t_fmt))) == NULL)
		return (-1);
	tmp_fmt->prec_val = -1;
	*fmt_p = tmp_fmt;
	return (0);
}

static inline int		fmt_proc(t_list *heads[3], const char *format, va_list ap)
{
	const char	*ch_p;
	t_list		*tmp_node;
	t_fmt		*tmp_fmt;
	ptrdiff_t	m;

	while ((ch_p = ft_strchrnul(format, '%')))
	{
		if ((m = fmt_as_str(format, ch_p - format, &heads[0])) < 0)
			return (m);
		if (*ch_p == '\0' || *++ch_p == '\0')
			return (0);
		ft_lstadd(&heads[0], ft_lstnew(NULL, 0));
		if (fmt_prep(&tmp_fmt) == -1)
			return (-1);
		if ((m = fmt_parser(tmp_fmt, ch_p, &heads[2], ap)) < 0)
			return (m);
		format = ch_p + m;
		if ((tmp_node = ft_lstnew(tmp_fmt, sizeof(t_fmt))) == NULL)
			return (-1);
		ft_memdel((void **)&tmp_fmt); //ft_delone?
		ft_lstadd(&heads[1], tmp_node);
	}
	return (0);
}

static inline int		vasprintf_error(t_list *heads[3])
{
	ft_lstdel(&heads[0], ft_lstdelcontent);
	ft_lstdel(&heads[1], ft_lstdelcontent);
	ft_lstdel(&heads[2], ft_lstdelcontent);
	return (-1);
}

int						ft_vasprintf(char **result_ptr, const char *format,
																va_list args)
{
	t_list	*heads[3] = {NULL, NULL, NULL};
	int		res;

	if (fmt_proc(heads, format, args) < 0)
		return (vasprintf_error(heads));
	ft_lstrev(&heads[0]);
	ft_lstrev(&heads[1]);
	ft_lstrev(&heads[2]);
	if (heads[2] != NULL)
		pos_proc(&heads[2], heads[1]);
	if (build_out_node(heads[0], heads[1], heads[2], args) < 0)
		return (vasprintf_error(heads));
	if ((res = build_fstr(result_ptr, heads[0])) < 0)
		return (-1);
	return (res);
}
