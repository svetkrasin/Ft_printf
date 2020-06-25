/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:46:55 by skrasin           #+#    #+#             */
/*   Updated: 2020/05/19 11:12:37 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	const size_t size = ft_strnlen(src, len);

	if (len > size)
		ft_memset(dst + size, '\0', len - size);
	return (ft_memcpy(dst, src, size));
}
