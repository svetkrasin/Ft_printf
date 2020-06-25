/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optmemalign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 13:24:36 by svet              #+#    #+#             */
/*   Updated: 2020/05/16 09:00:38 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

size_t	ft_optmemalign(const void *const s)
{
	const size_t xl = OPT_SIZE - (unsigned OP_T)s & OPT_MASK;

	if (xl == 8)
		return (0);
	else
		return (xl);
}
