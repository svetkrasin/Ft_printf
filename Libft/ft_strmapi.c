/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:37:24 by skrasin           #+#    #+#             */
/*   Updated: 2019/10/03 23:53:21 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fstr;
	char			*fstrcpy;
	unsigned int	n;

	n = 0;
	if (s && (fstr = ft_strnew(ft_strlen(s))))
	{
		fstrcpy = fstr;
		while (*s)
			*fstr++ = f(n++, *s++);
		return (fstrcpy);
	}
	return (NULL);
}
