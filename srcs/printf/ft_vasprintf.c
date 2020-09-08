/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:05:57 by svet              #+#    #+#             */
/*   Updated: 2020/09/07 20:50:18 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"
#include "ft_builder.h"
#include <sys/_types/_null.h>
#include <sys/_types/_ptrdiff_t.h>

static inline int	vasprintf_error(t_list *heads[3])
{
	ft_lstdel(&heads[0], ft_lstdelcontent);
	ft_lstdel(&heads[1], ft_lstdelcontent);
	ft_lstdel(&heads[2], ft_lstdelcontent);
	return (-1);
}

int					ft_vasprintf(char **result_ptr, const char *format,
																va_list args)
{
	t_list	*heads[3];
	int		res;

	heads[0] = NULL;
	heads[1] = NULL;
	heads[2] = NULL;
	if (fmt_proc(heads, format, args) == -1)
		return (vasprintf_error(heads));
	if (heads[2] != NULL)
	{
		pos_proc(&heads[2], heads[1]);
		if (build_out_pos(heads[0], heads[1], heads[2], args) == -1)
			return (vasprintf_error(heads));
	}
	if ((res = build_fstr(result_ptr, heads[0])) < 0)
		return (-1);
	return (res);
}
