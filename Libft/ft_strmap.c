/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:12:46 by skrasin           #+#    #+#             */
/*   Updated: 2019/10/03 13:46:20 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *fstr;
	char *fstrcpy;

	if (s && (fstr = ft_strnew(ft_strlen(s))))
	{
		fstrcpy = fstr;
		while (*s)
			*fstr++ = f(*s++);
		return (fstrcpy);
	}
	return (NULL);
}
