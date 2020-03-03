/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:02:17 by skrasin           #+#    #+#             */
/*   Updated: 2020/03/02 22:57:15 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_realloc(void *ptr, size_t size)
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

char		*ft_strchrnul(const char *s, char c)
{
	while (*s != (unsigned char)c && *s)
		s++;
	return (s);
}

int		ft_beginnwork(t_printf *node)
{
	node->cp = node->fmt;
	while ((node->ch = *(node->fmt)) != '\0' && node->ch != '%')
		node->fmt++;
	if ((node->n = node->fmt - node->cp) != 0)
	{
		if ((unsigned)node->ret + node->n > INT_MAX)
		{
			node->ret = 0;
			errno = EOVERFLOW;
			return (ft_error(node));
		}
		ft_outstring(&node->fstring, node->cp, node->n);
		node->ret += node->n;
	}
	if (node->ch == '\0')
		return (0);
	node->fmt++;
	node->flags = 0;
	node->dprec = 0;
	node->width = 0;
	node->prec = -1;
	node->gs.grouping = NULL;
	node->sign = '\0';
	node->ox[1] = '\0';
	return (1);
}

static void	ft_prep_struct(t_printf *node, const char *fmt, va_list arg)
{
	node->convbuf = NULL;
	node->fmt = fmt;
	node->argtable = NULL;
	node->nextarg = 1;
	va_copy(node->orgap, arg);
	node->ret = 0;
	node->dtoaresult = NULL;
	node->decimal_point = NULL; //read !470!
	node->decpt_len = 1;
	node->fstring = NULL;
	node->origfmt = fmt;
}

int			ft_parsedigits(t_printf *node) //has 26 lines!!!
{
	if (ft_is_digit(node->ch))
	{
		node->n = 0;
		while (ft_is_digit(node->ch))
		{
			node->n = 10 * node->n + ft_to_digit(node->ch);
			node->ch = *node->fmt++;
		}
		if (node->ch == '$')
		{
			node->nextarg = node->n;
			if (node->argtable == NULL)
			{
				node->argtable = node->statargtable;
				if (ft_find_arguments(node))
				{
					node->ret = 0;
					return (ft_error(node));
				}
			}
			ft_parseflags(node);
		}
		node->width = node->n;
		node->ch = *node->fmt--;
		ft_parseflags(node);
	}
}

int			ft_parseprec(t_printf *node)
{
	if (node->ch == '.')
	{
		if ((node->ch = *node->fmt++) == '*')
		{
			ft_getaster(node->prec);
			ft_parseflags(node);
		}
		node->prec = 0;
		while (ft_is_digit(node->ch))
		{
			node->prec = 10 * node->prec + ft_to_digit(node->ch);
			node->ch = *node->fmt++;
		}
		node->ch = *node->fmt--;
		ft_parseflags(node);
	}
	if (node->ch == '0')
	{
		node->flags |= ZEROPAD;
		ft_parseflags(node);
	}
	return (ft_parsedigits(node));
}

int			ft_proceedparseflags(t_printf *node)
{
	if (node->ch == '+')
	{
		node->sign = '+';
		ft_parseflags(node);
	}
	if (node->ch == '\'')
	{
		node->flags |= GROUPING;
		ft_parseflags(node);
	}
	return (ft_parseprec(node));
}

int			ft_parseflags(t_printf *node)
{
	node->ch = *node->fmt++;
	if (node->ch == ' ')
	{
		if (!node->sign)
			node->sign = ' ';
		ft_parseflags(node);
	}
	if (node->ch == '#')
	{
		node->flags |= ALT;
		ft_parseflags(node);
	}
	if (node->ch == '*')
	{
		ft_getaster(node);
		if (!node->width >= 0)
			ft_parseflags(node);
		node->width *= -1;
	}
	if (node->ch == '-')
	{
		node->flags |= LADJUST;
		ft_parseflags(node);
	}
	return(ft_proceedparseflags(node));
}

int			ft_basicwork(t_printf *node)
{
	int check;

	while (true)
	{
		if ((check = ft_beginwork(node)) < 1)
			return (check);
		if ((check = ft_parseflags(node)) < 1)
			return (check);
		
	}
	return (check);
}

int			ft_vasprintf(char **result_ptr, const char *format, va_list args)
{
	t_printf *node;

	if (!(node = (t_printf *)ft_memalloc(sizeof(t_printf))))
		return (-1);
	ft_prepstruct(node, format, args);
	ft_basicwork(node);
	return (node->ret);
}
