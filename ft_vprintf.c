/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:04:28 by svet              #+#    #+#             */
/*   Updated: 2020/01/06 18:15:06 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <errno.h>

int	ft_vprintf(int fd, const char *restrict format, va_list ap)
{
	va_list	ap_save;
	int		save_errno;

	save_errno = errno;
	if (fd < 0 || format == NULL)
		return (0);
	while (*format != 0)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			if (*format == 'd' || *format == 'i')
				ft_putnbr(ft_atoi(va_arg(ap_save, int)));
		}
		else
			ft_putchar(*format);
	}
	return (1);
}
