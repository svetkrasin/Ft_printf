/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:56:31 by skrasin           #+#    #+#             */
/*   Updated: 2020/03/08 05:46:46 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

const char	*ft_strchrnul(const char *s, char c)
{
	while (*s != (unsigned char)c && *s)
		s++;
	return (s);
}

int			ft_check_ret(int curret, int newret)
{
	if (INT_MAX - curret < newret)
	{
		errno = EOVERFLOW;
		curret = -1;
	}
	else
		curret += newret;
	return (-1);
}

int			ft_pf_todigit(char c)
{
	return ((c) - '0');
}

int			ft_pf_isdigit(char c)
{
	return ((unsigned int)ft_pf_todigit(c) < 10);
}

char		ft_pf_ftochar(char n)
{
	return ((n) + '0');
}
