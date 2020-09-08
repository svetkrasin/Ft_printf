/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:20:10 by skrasin           #+#    #+#             */
/*   Updated: 2020/09/01 20:16:30 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <sys/_types/_null.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (ft_memcmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
