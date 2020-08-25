/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:36:04 by svet              #+#    #+#             */
/*   Updated: 2020/08/20 15:06:45 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <sys/_types/_null.h>

char	*ft_memappend(void **dst, char const *src, size_t dlen, size_t slen)
{
	char	*prev_str;
	char	*new_str;

	if (dst == NULL || *dst == NULL || src == NULL)
		return (NULL);
	prev_str = *dst;
	if ((new_str = ft_memalloc(dlen + slen)) == NULL)
		return (NULL);
	ft_memcpy(new_str, prev_str, dlen);
	ft_memcpy(new_str + dlen, src, slen);
	ft_memdel(dst);
	return ((*dst = new_str));
}
