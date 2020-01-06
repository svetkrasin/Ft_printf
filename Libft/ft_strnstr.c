/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:08:38 by skrasin           #+#    #+#             */
/*   Updated: 2019/10/05 02:40:59 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haysteck, const char *needle, size_t len)
{
	size_t	n;

	if (*needle)
	{
		n = ft_strlen(needle);
		while (ft_strncmp(haysteck, needle, n) && n <= len && len-- &&
															*haysteck)
			haysteck++;
		if (!*haysteck || !len || n > len)
			return (NULL);
	}
	return ((char *)haysteck);
}
