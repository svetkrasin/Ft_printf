/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:04:28 by svet              #+#    #+#             */
/*   Updated: 2020/02/26 20:19:32 by skrasin          ###   ########.fr       */
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
		__set_erno(EBADF);
		return (-1);
	}
	if (format == NULL)
	{
		__set_erno(EINVAL);
		return (-1);
	}
	return (1);
}
