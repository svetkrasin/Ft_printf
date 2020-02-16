/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:04:28 by svet              #+#    #+#             */
/*   Updated: 2020/02/16 00:56:03 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <errno.h>
#include <assert.h>
#include <limits.h>
#include <wctype.h>

const char			*grouping;
int					done;
const unsigned char	*f;
const unsigned char	*lead_str_end;
const unsigned char	*end_of_spec;
va_list				ap_save;
int					nspecs_done;
int					save_errno;
int					readonly_format;
char				work_buffer[1000 / sizeof(char)];
char				*workstart;
char				workend;

const unsigned char	*find_specmb(const unsigned char *format)
{
	return ((const unsigned char *)ft_strchr((const char *)format, '%'));
}

void	outstring(char *string, int len)
{
	assert((size_t)done <= (size_t)INT_MAX);
	if ((size_t)write(fd, string, len) != (size_t)len)
	{
		done = -1;
		return (done); //check goto
	}
}

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
	readonly_format = 0;
	save_errno = errno;
	done = 0;
	grouping = (const char *)-1;
	nspecs_done = 0;
	lead_str_end = find_specmb((const unsigned char *)format);
	f = lead_str_end;
	workstart = NULL;
	return (1);
}
