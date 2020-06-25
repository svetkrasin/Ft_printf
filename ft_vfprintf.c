/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:04:28 by svet              #+#    #+#             */
/*   Updated: 2020/06/08 22:08:50 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <errno.h>
#include <assert.h>
#include <limits.h>
#include <wctype.h>

int	ft_vfprintf(int fd, const char *restrict format, va_list ap,
													unsigned int mode_flags)
{
	if (fd < 0)
	{
		errno = EBADF;
		return (-1);
	}
	if (format == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	return (1);
}
