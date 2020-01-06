/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:01:00 by skrasin           #+#    #+#             */
/*   Updated: 2019/09/26 06:05:07 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char *l;

	l = NULL;
	if (*s)
	{
		while (*s)
		{
			if (*s == c)
				l = (char *)s;
			s++;
		}
		if (!c)
			return ((char *)s);
		return (l);
	}
	return (NULL);
}
