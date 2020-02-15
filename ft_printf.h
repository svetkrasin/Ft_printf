/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 10:32:11 by svet              #+#    #+#             */
/*   Updated: 2020/02/14 22:41:20 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "Libft/libft.h"

typedef struct	s_printf
{
	int			done;
	va_list		ap_save;
	int			param;
	char		flags;
	int			width;
	int			precision;
	int			length;
	char		type;
}				t_printf;

int				ft_printf(const char *restrict format, ...);
int				ft_vprintf(int fd, const char *restrict format, va_list ap);

#endif
