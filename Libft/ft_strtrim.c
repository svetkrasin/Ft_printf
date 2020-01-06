/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:34:27 by skrasin           #+#    #+#             */
/*   Updated: 2019/10/02 20:59:44 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int				ft_check(char c)
{
	return (c == 32 || c == 10 || c == 9);
}

static unsigned int		ft_skip(char const *s)
{
	unsigned int n;

	n = 0;
	while (*s && ft_check(*s++))
		n++;
	return (n);
}

static size_t			ft_trim_end(char const *s, size_t n)
{
	while (--n && ft_check(*(s + n)))
		continue ;
	return (n);
}

char					*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			end;

	if (s)
	{
		start = ft_skip(s);
		end = ft_trim_end(s, ft_strlen(s));
		if (start > end)
			return (ft_strnew(0));
		return (ft_strsub(s, start, end - start + 1));
	}
	return (NULL);
}
