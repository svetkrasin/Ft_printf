/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unum_of_digs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:01:15 by svet              #+#    #+#             */
/*   Updated: 2020/09/01 20:11:01 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

unsigned int	ft_unum_of_digs(uintmax_t n, int base)
{
	unsigned int l;

	l = n == 0 ? 1 : 0;
	if (base < 2 || base > 36)
		return (0);
	while (n != 0)
	{
		n /= (uintmax_t)base;
		++l;
	}
	return (l);
}
