/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:38:37 by skrasin           #+#    #+#             */
/*   Updated: 2019/09/28 18:42:16 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *substr;
	char *substrcpy;

	if (s && (substr = ft_strnew(len)))
	{
		substrcpy = substr;
		while (len--)
			*substr++ = *(s++ + start);
		return (substrcpy);
	}
	return (NULL);
}
