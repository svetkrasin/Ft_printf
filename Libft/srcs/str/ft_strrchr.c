/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:01:00 by skrasin           #+#    #+#             */
/*   Updated: 2020/05/05 14:59:14 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <sys/_types/_null.h>

char	*ft_strrchr(const char *s, int c)
{
	const char *p;
	const char *f;

	if (c == '\0')
		return (ft_strchr(s, '\0'));
	f = NULL;
	c = (unsigned char)c;
	while ((p = ft_strchr(s, c)) != NULL)
	{
		f = p;
		s = p + 1;
	}
	return ((char *)f);
}
