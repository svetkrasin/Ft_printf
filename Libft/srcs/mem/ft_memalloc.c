/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:58:27 by skrasin           #+#    #+#             */
/*   Updated: 2020/06/08 17:25:15 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*const new = malloc(size);

	if (new == NULL)
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
