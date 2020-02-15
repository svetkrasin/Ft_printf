/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 10:30:46 by svet              #+#    #+#             */
/*   Updated: 2020/02/14 22:22:12 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		ft_printf(const char *restrict format, ...)
{
	va_list arg;
	int		done;

	va_start(arg, format);
	done = ft_vfprintf(STDOUT_FILENO, format, arg, 0);
	va_end(arg);
	return (done);
}
