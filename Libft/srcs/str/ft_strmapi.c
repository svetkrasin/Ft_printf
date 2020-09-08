/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:37:24 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/01 19:52:19 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <sys/_types/_null.h>

char	*ft_strmapi(char const *s, char (*f)(size_t, char))
{
	char	*fstr;
	char	*fstrcpy;
	size_t	n;

	n = 0;
	if (s == NULL || (fstr = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	fstrcpy = fstr;
	while (*s != '\0')
		*fstr++ = f(n++, *s++);
	return (fstrcpy);
}
