/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memaligncmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 11:26:27 by svet              #+#    #+#             */
/*   Updated: 2020/09/01 18:23:37 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

size_t	ft_memaligncmp(
	const void *const *const ds,
	const void *const *const sr,
	const size_t nbytes,
	const unsigned long align
)
{
	const long	dst = (const long)*(const long *const*const)ds;
	const long	src = (const long)*(const long *const*const)sr;
	long		t;

	t = src;
	if ((t | dst) & ((long)align - 1))
	{
		if ((t ^ dst) & ((long)align - 1) || nbytes < align)
			t = (long)nbytes;
		else
			t = (long)align - (t & ((long)align - 1));
		return ((size_t)t);
	}
	return (0);
}
