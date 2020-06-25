/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbetween.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 11:43:33 by svet              #+#    #+#             */
/*   Updated: 2020/06/08 17:19:05 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

int	ft_isbetween(int x, int m, int n)
{
	return ((int)(((((unsigned long)x) - ~0UL / 255 * ((unsigned long)n)) &
		~((unsigned long)x) & (((unsigned long)x) & ~0UL / 255 * 127) + ~0UL /
						255 * (127 - ((unsigned long)m))) & ~0UL / 255 * 128));
}
