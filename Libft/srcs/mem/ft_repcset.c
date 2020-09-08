/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repcset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 13:43:37 by svet              #+#    #+#             */
/*   Updated: 2020/09/01 18:56:43 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

unsigned long	ft_repcset(int c)
{
	register unsigned long cc;

	if ((cc = (unsigned char)c) != 0)
	{
		cc |= cc << 8;
		cc |= cc << 16;
		if (sizeof(long) > 4)
			cc |= cc << 32;
	}
	else
		cc = 0x00;
	return (cc);
}
