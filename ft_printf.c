/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 10:30:46 by svet              #+#    #+#             */
/*   Updated: 2020/02/26 21:18:29 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		ft_printf(const char *restrict format, ...)
{
	va_list arg;
	int		done;
	char	*fstr;

	va_start(arg, format);
	done = ft_vasprintf(&fstr, format, arg);
	va_end(arg);
	write(STDOUT_FILENO, fstr, done);
	return (done);
}
