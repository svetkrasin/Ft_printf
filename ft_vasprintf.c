/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:02:17 by skrasin           #+#    #+#             */
/*   Updated: 2020/02/27 23:11:04 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <errno.h>
#include <limits.h>

char			*ft_realloc(void *ptr, size_t size)
{
	free(ptr);
	ptr = (char *)malloc(size);
	return (ptr);
}

char		*ft_outstring(char **dst, char const *src, size_t len)
{
	char	*tmp;
	size_t	n1;

	if (dst && src)
	{
		if (*dst)
		{
			tmp = *dst;
			n1 = ft_strlen(*dst);
			if ((*dst = ft_memalloc(n1 + ft_strlen(src) + 1)))
			{
				ft_memcpy(*dst, tmp, n1);
				ft_memcpy(*dst + n1 + 1, src, len + 1);
			}
			free(tmp);
		}
		else if ((*dst = ft_memalloc(len + 1)))
			ft_memcpy(*dst, src, len + 1);
	}
	return (*dst);
}

static int			ft_prep_struct(t_printf *node, const char *fmt, va_list arg)
{
	va_copy(node->ap_save, arg);
	node->thousands_sep = 0;
	node->save_errno = errno;
	if (fmt == NULL && (errno = EINVAL))
		return (-1);
	node->format = fmt;
	node->fstring = NULL;
	node->grouping = (const char *)-1;
	node->lead_str_end = (const unsigned char *)ft_strchr(fmt, '%');
	node->f = node->lead_str_end;
	ft_outstring(&(node->fstring), (const unsigned char *)fmt, node->f - (const unsigned char *)fmt);
	if (*(node->f) == '\0')
	{
		if ((size_t)node->done > (size_t)INT_MAX && (errno = EOVERFLOW))
			return (-1);
		else
			return (node->f - (const unsigned char *)fmt);
	}
	node->done = node->f - (const unsigned char *)fmt;
	return(node->done);
}

int				ft_vasprintf(char **result_ptr, const char *format,
																va_list args)
{
	t_printf *node;

	if (!(node = (t_printf *)ft_memalloc(sizeof(t_printf))))
		return (-1);
	if (ft_prepstruct(node, format, args) == -1)
	{
		free(node->fstring);
		free(node);
		return(-1);
	}
	if (*(node->f) == '\0')
	{
		if (!(*result_ptr = (char *)ft_memalloc(node->done * sizeof(char))))
			return (-1);
		ft_memcpy(*result_ptr, node->fstring, node->done);
		return (node->done);
	}
	return (node->done);
}
