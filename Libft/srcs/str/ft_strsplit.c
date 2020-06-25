/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 22:06:48 by svet              #+#    #+#             */
/*   Updated: 2020/05/19 12:05:23 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <sys/_types/_null.h>

static inline const char	*ft_skip(char const *s, char c)
{
	while (*s != '\0' && *s == c)
		s++;
	return (s);
}

static inline size_t		ft_len_word(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static inline size_t		ft_all_words(char const *s, char c)
{
	size_t i;
	size_t n;

	i = 0;
	while (*s != '\0')
	{
		s = ft_skip(s, c);
		n = ft_len_word(s, c);
		if (n == 0)
			return (i);
		i++;
		s += n;
	}
	return (i);
}

char						**ft_strsplit(char const *s, char c)
{
	char	**arrstr;
	size_t	i;
	size_t	n;
	size_t	m;

	if (s == NULL)
		return (NULL);
	i = -1;
	n = ft_all_words(s, c);
	if ((arrstr = (char **)ft_memalloc((n + 1) * sizeof(char *))))
	{
		while (++i < n)
		{
			s = ft_skip(s, c);
			m = ft_len_word(s, c);
			arrstr[i] = (char *)ft_memalloc((m + 1) * sizeof(char));
			arrstr[i] = ft_strncpy(arrstr[i], s, m);
			s += m;
		}
		return (arrstr);
	}
	return (NULL);
}
