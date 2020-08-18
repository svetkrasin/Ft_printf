/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:34:27 by skrasin           #+#    #+#             */
/*   Updated: 2020/07/21 18:31:07 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <sys/_types/_null.h>

static inline size_t	ft_skip(char const *s, char const *set)
{
	size_t	n;

	n = 0;
	while (*s != '\0' && ft_strchr(set, *s++) != NULL)
		n++;
	return (n);
}

static inline size_t	ft_trim_end(char const *s, char const *set, size_t n)
{
	while (n != 0 && ft_strchr(set, *(s + n)) != NULL)
		--n;
	return (n);
}

char					*ft_strtrim(char const *str, char const *set)
{
	size_t	start;
	size_t	end;

	if (str == NULL)
		return (NULL);
	start = ft_skip(str, set);
	end = ft_trim_end(str, set, ft_strlen(str));
	if (start > end)
		return (ft_strnew(0));
	return (ft_strsub(str, start, end - start + 1));
}
