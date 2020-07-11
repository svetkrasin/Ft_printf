/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 10:32:11 by svet              #+#    #+#             */
/*   Updated: 2020/07/11 11:35:29 by svet             ###   ########.fr       */
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

# define FL_ALT			0x001
# define FL_SIGN		0x002
# define FL_SPACE		0x004
# define FL_ZEROPAD		0x008
# define FL_LADJUST		0x010
# define FL_SHORTINT	0x020
# define FL_MAXINT		0x040
# define FL_LONGINT		0x080
# define FL_QUADINT		0x100
# define FL_PTRDIFF		0x200
# define FL_SIZEINT		0x400
# define FL_CHARINT		0x800

typedef struct	s_fmt
{
	size_t		param;
	int			flags;
	int			width_val;
	size_t		width_pos;
	int			prec_val;
	size_t		prec_pos;
	char		type;
}				t_fmt;

typedef struct	s_pos
{
	size_t		n;
	char		type;
	int			flags;
}				t_pos;

int				ft_vasprintf(char **result_ptr, const char *format, va_list args);

const char		*fmt_flags(const char *format, t_fmt *fmt);
int				fmt_pos_or_width(const char **format_p, t_fmt *fmt, t_list **pos_p);
int				fmt_aster(const char **format_p, t_fmt *fmt, t_list **pos_p, va_list ap);
int				fmt_dot(const char **format_p, t_fmt *fmt, t_list **pos_p, va_list ap);
int				fmt_lenght_and_type(const char **format_p, t_fmt *fmt);
int				fmt_width(long n, t_fmt *fmt);
void			fmt_upd_flags(int flag, t_fmt *fmt);
int				fmt_prec(long n, t_fmt *fmt);
int				fmt_set_prec(int value, unsigned long param, t_fmt *fmt);

int				fmt_pos(unsigned long n, char type, t_fmt *fmt, t_list **pos_p);
int				fmt_eoverflow(long n);

void			pos_proc(t_list **pos_head_p, t_list *fmt_head);

int				build_out_node(t_list *out_node, t_list *fmt_node, t_list *pos_head, va_list ap);

unsigned long	ft_strtoul(const char *nptr, char **endptr, int base);

#endif
