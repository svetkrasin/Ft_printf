/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:02:17 by skrasin           #+#    #+#             */
/*   Updated: 2020/07/07 18:20:07 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline ptrdiff_t	fmt_parser(t_fmt *fmt, const char *format,
													t_list **pos_p, va_list ap)
{
	const char	*format_cpy = format;
	int			ret;

	while (1)
		if (ft_memchr("#0 +-", *format, 6) != NULL)
			format = fmt_flags(format, &fmt->flags);
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
		else if (fmt_lenght_and_type(&format, fmt))
			return (format - format_cpy);
		else
			return (0);
}

static inline int	fmt_str(const char *format, ptrdiff_t m, t_list ***out_node_p)
{
	t_list	*tmp_node;

	if (m > INT_MAX)
		return (-2);
	if ((tmp_node = ft_lstnew(format, m)) == NULL)
		return (-1);
	ft_lstadd(*out_node_p, tmp_node);
	return (0);
}

static inline int	fmt_prep(t_fmt **fmt_p)
{
	t_fmt	*tmp_fmt;

	if ((tmp_fmt = (t_fmt *)ft_memalloc(sizeof(t_fmt))) == NULL)
		return (-1);
	tmp_fmt->prec_value = -1;
	*fmt_p = tmp_fmt;
	return (0);
}

static inline int	fmt_proc(t_list **out_node, t_list *fmt_node,
								t_list **pos_p, const char *format, va_list ap)
{
	const char	*ch_p;
	t_list		*tmp_node;
	t_fmt		*tmp_fmt;
	ptrdiff_t	m;

	while (1)
	{
		if ((ch_p = ft_strchrnul(format, '%')) - format != 0 &&
							(m = fmt_str(format, ch_p - format, &out_node)) < 0)
			return (m);
		if (*ch_p == '\0' || *++ch_p == '\0')
			return (0);
		ft_lstadd(out_node, ft_lstnew(NULL, 0));
		if (fmt_prep(&tmp_fmt) < 0)
			return (-1);
		if ((m = fmt_parser(tmp_fmt, ch_p, pos_p, ap)) < 0)
			return (m);
		format = ch_p + m;
		if ((tmp_node = ft_lstnew(tmp_fmt, sizeof(t_fmt))) == NULL)
			return (-1);
		ft_memdel((void **)&tmp_fmt); //delone?
		ft_lstadd(&fmt_node, tmp_node);
	}
	return (0);
}

static inline void	pos_proc(t_list *pos_node, t_list *fmt_node) //sort and delete repeats?
{
	while (pos_node != NULL)
	{
		if (((t_pos *)(pos_node->content))->type == 0)
		{
			while(((t_fmt *)(fmt_node->content))->param != ((t_pos *)(pos_node->content))->n)
				fmt_node = fmt_node->next;
			((t_pos *)(pos_node->content))->type = ((t_pos *)(pos_node->content))->type;
		}
		pos_node = pos_node->next;
	}
}

int					ft_vasprintf(char **result_ptr, const char *format,
																va_list args)
{
	const int	save_errno = errno;
	t_list		*fmt_head;
	t_list		*out_head;
	t_list		*pos_head;

	fmt_head = ft_lstnew(NULL, 0);
	out_head = ft_lstnew(NULL, 0);
	pos_head = ft_lstnew(NULL, 0);
	if (fmt_proc(&out_head, fmt_head, &pos_head, format, args) < 0)
		return (-1); //delete lists?
	if (pos_head->next != NULL)
		pos_proc(pos_head, fmt_head);
	return (1);
	build_str(out_head, fmt_head, pos_head, args);
}
