/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:08:38 by skrasin           #+#    #+#             */
/*   Updated: 2020/05/15 12:36:45 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <sys/_types/_null.h>

char	*ft_strnstr(const char *haysteck, const char *needle, size_t len)
{
	register size_t	l;
	register char	cn;
	register char	ch;

	if ((cn = *needle++) != '\0')
	{
		l = ft_strlen(needle);
		while (l <= len && len-- != 0 && (ch = *haysteck++) != '\0')
			if (ch == cn && ft_strncmp(haysteck, needle, l) == 0)
				return ((char *)haysteck - 1);
		return (NULL);
	}
	return ((char *)haysteck);
}
