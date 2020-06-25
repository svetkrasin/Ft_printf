/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repcset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 13:43:37 by svet              #+#    #+#             */
/*   Updated: 2020/05/14 14:19:32 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

unsigned OP_T	ft_repcset(int c)
{
	register unsigned OP_T cc;

	if ((cc = (unsigned char)c) != 0)
	{
		cc |= cc << 8;
		cc |= cc << 16;
		cc |= cc << 32;
	}
	else
		cc = 0x00;
	return (cc);
}
