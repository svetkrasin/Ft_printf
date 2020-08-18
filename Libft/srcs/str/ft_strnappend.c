/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 07:16:27 by svet              #+#    #+#             */
/*   Updated: 2020/07/20 16:37:03 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <sys/_types/_null.h>

char	*ft_strnappend(char **dst, char const *src, size_t n)
{
	char	*prev_str;
	char	*new_str;
	size_t	dlen;
	size_t	slen;

	if (dst == NULL)
		return (NULL);
	prev_str = *dst;
	dlen = ft_strlen(prev_str);
	slen = ft_strnlen(src, n);
	if ((new_str = ft_strnew(dlen + slen)) == NULL)
		return (NULL);
	ft_memcpy(new_str, prev_str, dlen);
	ft_memcpy(new_str + dlen, src, slen);
	ft_strdel(dst);
	return ((*dst = new_str));
}
