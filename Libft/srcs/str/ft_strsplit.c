/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 22:06:48 by svet              #+#    #+#             */
/*   Updated: 2020/07/24 13:17:53 by svet             ###   ########.fr       */
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

static inline void			ft_del(char ***arrstr, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
		ft_strdel(*arrstr + i++);
	ft_memdel((void **)arrstr);
}

char						**ft_strsplit(char const *s, char c)
{
	char	**arrstr;
	size_t	i;
	size_t	n;
	size_t	m;

	if (s == NULL)
		return (NULL);
	i = 0;
	n = ft_all_words(s, c);
	if ((arrstr = (char **)ft_memalloc((n + 1) * sizeof(char *))) == NULL)
		return (NULL);
	while (i < n)
	{
		s = ft_skip(s, c);
		m = ft_len_word(s, c);
		if ((arrstr[i] = ft_strnew(m)) == NULL)
		{
			ft_del(&arrstr, i);
			return (NULL);
		}
		arrstr[i] = ft_strncpy(arrstr[i], s, m);
		s += m;
		i++;
	}
	return (arrstr);
}
