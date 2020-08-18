/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 07:15:19 by svet              #+#    #+#             */
/*   Updated: 2020/07/20 14:58:01 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <sys/_types/_null.h>

char	*ft_strchrnul(const char *s, char c)
{
	const size_t	len = ft_strlen(s) + 1;
	const char		*p_ch = ft_memchr(s, c, len);

	if (p_ch == NULL)
		return ((char *)s + len - 1);
	return ((char *)p_ch);
}
