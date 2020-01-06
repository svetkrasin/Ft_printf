/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:04:28 by svet              #+#    #+#             */
/*   Updated: 2020/01/01 16:23:33 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <errno.h>

int			ft_vprintf(int fd, const char *restrict format, va_list ap)
{
	va_list ap_save;
	int save_errno = errno;

	if (fd < 0 || format == NULL)
		return (0);
	while (*format != 0)
	{
		if (*format != '%')
			ft_putchar(*format);
		format++;
	}
	return (1);
}
