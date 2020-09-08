/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optmemalign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 13:24:36 by svet              #+#    #+#             */
/*   Updated: 2020/09/01 18:56:03 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

size_t	ft_optmemalign(const void *const s)
{
	const size_t long_size = sizeof(long);
	const size_t xl = long_size - (unsigned long)(long)s & (long_size - 1);

	return (xl == long_size ? 0 : xl);
}
