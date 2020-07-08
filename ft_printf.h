/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 10:32:11 by svet              #+#    #+#             */
/*   Updated: 2020/07/07 18:20:02 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <sys/types.h>
# include <stddef.h>
# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include "./Libft/includes/libft.h"
# include <sys/_types/_wint_t.h>
# include <stdlib.h>

#define FMT_P			content

# define FL_HASH		0x1L
# define FL_ZERO		0x2L
# define FL_SPACE		0x4L
# define FL_PLUS		0x8L
# define FL_MINUS		0x10L
# define FL_ASTER		0x20L
# define SHIFT_WIDTH	sizeof(int) * 8

typedef struct	s_fmt
{
	size_t		param;
	char		flags;
	int			width_value;
	size_t		width_param;
	int			prec_value;
	size_t		prec_param;
	char		length;
	char		type;
}				t_fmt;

typedef struct	s_pos
{
	long		n;
	char		type;
}				t_pos;

int			ft_vasprintf(char **result_ptr, const char *format, va_list args);

const char	*fmt_flags(const char *format, char *fmt_flags);
int			fmt_pos_or_width(const char **format_p, t_fmt *fmt, t_list **pos_p);
int			fmt_aster(const char **format_p, t_fmt *fmt, t_list **pos_p, va_list ap);
int			fmt_dot(const char **format_p, t_fmt *fmt, t_list **pos_p, va_list ap);
int			fmt_lenght_and_type(const char **format_p, t_fmt *fmt);

int			fmt_pos(unsigned long n, char type, t_fmt *fmt, t_list **pos_p);
int			fmt_eoverflow(long n);

unsigned long	ft_strtoul(const char *nptr, char **endptr, int base);


#endif
