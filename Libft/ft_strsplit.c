/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:49:28 by skrasin           #+#    #+#             */
/*   Updated: 2019/10/03 12:45:56 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static const char		*ft_skip(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

static size_t			ft_len_word(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static size_t			ft_all_words(char const *s, char c)
{
	size_t i;
	size_t n;

	i = 0;
	while (*s)
	{
		s = ft_skip(s, c);
		n = ft_len_word(s, c);
		if (!n)
			return (i);
		i++;
		s += n;
	}
	return (i);
}

char					**ft_strsplit(char const *s, char c)
{
	char	**arrstr;
	size_t	i;
	size_t	n;
	size_t	m;

	if (s)
	{
		i = -1;
		n = ft_all_words(s, c);
		if ((arrstr = (char **)ft_memalloc((n + 1) * sizeof(char *))))
		{
			while (++i < n)
			{
				s = ft_skip(s, c);
				m = ft_len_word(s, c);
				arrstr[i] = ft_strnew(m);
				arrstr[i] = ft_strncpy(arrstr[i], s, m);
				s += m;
			}
			return (arrstr);
		}
	}
	return (NULL);
}
