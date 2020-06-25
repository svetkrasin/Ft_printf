/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:31:04 by skrasin           #+#    #+#             */
/*   Updated: 2020/05/05 15:01:19 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"
#include <stdlib.h>
#include <sys/_types/_null.h>

char					*ft_strdup(const char *s)
{
	const size_t		len = ft_strlen(s) + 1;
	void *const			new = malloc(len);

	if (new == NULL)
		return (NULL);
	return (ft_memcpy(new, s, len));
}
