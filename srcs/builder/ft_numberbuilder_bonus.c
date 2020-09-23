/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberbuilder_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 23:43:53 by svet              #+#    #+#             */
/*   Updated: 2020/09/23 01:05:19 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builder.h"
#include "limits.h"
#include <sys/_types/_null.h>

int	build_number(t_dlist *out, void *n, int flags)
{
	const t_dlist *const	cpy = out;
	int						len;
	int						size;

	len = 0;
	out = ft_dlstedge(out, 0);
	while (out != cpy)
	{
		size = out->content_size;
		if (INT_MAX - len < size)
			return (-1);
		else
			len += size;
		out = out->next;
	}
	if (flags >= FL_MAXINT)
		*(intmax_t *)n = len;
	else if (flags & FL_SHORTINT)
		*(short *)n = len;
	else if (flags & FL_CHARINT)
		*(char *)n = len;
	else if (flags < FL_CHARINT)
		*(int *)n = len;
	out->content = NULL;
	return ((out->content_size = 0) + 1);
}
