/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:50:13 by svet              #+#    #+#             */
/*   Updated: 2020/09/01 19:50:48 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

unsigned long	ft_strtoul(const char *nptr, char **endptr, int base)
{
	return ((unsigned long)ft_strtol(nptr, endptr, base));
}
