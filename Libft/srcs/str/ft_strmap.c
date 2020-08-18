/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:12:46 by skrasin           #+#    #+#             */
/*   Updated: 2020/07/21 18:35:24 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <sys/_types/_null.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *fstr;
	char *fstrcpy;

	if (s == NULL || (fstr = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	fstrcpy = fstr;
	while (*s != '\0')
		*fstr++ = f(*s++);
	return (fstrcpy);
}
