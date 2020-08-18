/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:37:24 by skrasin           #+#    #+#             */
/*   Updated: 2020/07/21 18:35:03 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <sys/_types/_null.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fstr;
	char			*fstrcpy;
	unsigned int	n;

	n = 0;
	if (s == NULL || (fstr = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	fstrcpy = fstr;
	while (*s != '\0')
		*fstr++ = f(n++, *s++);
	return (fstrcpy);
}
