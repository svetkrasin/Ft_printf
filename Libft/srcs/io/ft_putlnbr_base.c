/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:08:44 by svet              #+#    #+#             */
/*   Updated: 2020/05/19 11:03:20 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <unistd.h>

void	ft_putlnbr_base(long n, int base, int isupper)
{
	ft_putlnbr_base_fd(n, base, isupper, STDOUT_FILENO);
}
