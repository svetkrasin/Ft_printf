/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 07:16:27 by svet              #+#    #+#             */
/*   Updated: 2020/07/10 14:54:41 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <stdlib.h>
#include <sys/_types/_null.h>

char	*ft_strnappend(char **dst, char const *src, size_t n)
{
	char *const		tmp = *dst;
	const size_t	dlen = ft_strlen(*dst);
	const size_t	slen = ft_strnlen(src, n);


	if ((*dst = ft_memalloc(dlen + slen + 1)) == NULL)
		return (NULL);
	*dst = ft_memcpy(*dst, tmp, dlen);
	ft_memcpy(*dst + dlen, src, slen);
	free(tmp);
	return (*dst);
}
