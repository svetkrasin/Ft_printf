/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 10:30:46 by svet              #+#    #+#             */
/*   Updated: 2019/12/28 13:35:44 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		ft_printf(const char *restrict format, ...)
{
	va_list arg;
	int done;

	va_start(arg, format);
	done = ft_vprintf(STDOUT_FILENO, format, arg);
	va_end(arg);
	return (done);
}
