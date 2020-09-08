/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:29:22 by svet              #+#    #+#             */
/*   Updated: 2020/09/01 20:08:11 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	ft_isnan(long double x)
{
	int32_t						hx;
	int32_t						lx;
	t_ieee_double_shape_type	ew_u;

	ew_u.value = x;
	hx = (int32_t)ew_u.parts.msw;
	lx = (int32_t)ew_u.parts.lsw;
	hx &= 0x7fffffff;
	hx |= (u_int32_t)(lx | (-lx)) >> 31;
	hx = 0x7ff00000 - hx;
	return (int)((u_int32_t)(hx)) >> 31;
}
