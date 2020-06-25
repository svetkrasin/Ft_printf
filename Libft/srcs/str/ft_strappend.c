/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:07:19 by svet              #+#    #+#             */
/*   Updated: 2020/05/30 20:30:19 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <stdlib.h>

char	*ft_strappend(char **dst, char const *src)
{
	char			*tmp;
	const size_t	n1 = ft_strlen(*dst);
	const size_t	n2 = ft_strlen(src);

	tmp = *dst;
	if ((*dst = ft_memalloc(n1 + n2 + 1)) == NULL)
		return (NULL);
	*dst = ft_memcpy(*dst, tmp, n1);
	ft_memcpy(*dst + n1, src, n2);
	free(tmp);
	return (*dst);
}
