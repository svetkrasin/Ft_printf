/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unum_of_digs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:01:15 by svet              #+#    #+#             */
/*   Updated: 2020/08/14 19:02:59 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_types/_uintmax_t.h>

unsigned int	ft_unum_of_digs(uintmax_t n, int base)
{
	unsigned int l;

	l = n == 0 ? 1 : 0;
	while (n != 0)
	{
		n /= base;
		++l;
	}
	return (l);
}
