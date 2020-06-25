/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:38:37 by skrasin           #+#    #+#             */
/*   Updated: 2020/05/18 22:55:44 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <sys/_types/_null.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *substr;

	if (s != NULL && (substr = (char *)ft_memalloc((len + 1) * sizeof(char))))
		return (ft_memcpy(substr, s + start, len));
	return (NULL);
}
