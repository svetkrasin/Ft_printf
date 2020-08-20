/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:22:06 by svet              #+#    #+#             */
/*   Updated: 2020/08/19 16:14:49 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H
# include "libft.h"
# include <stdarg.h>

# define FL_ALT			0x0001
# define FL_SIGN		0x0002
# define FL_SPACE		0x0004
# define FL_ZEROPAD		0x0008
# define FL_LADJUST		0x0010
# define FL_SHORTINT	0x0020
# define FL_MAXINT		0x0040
# define FL_LONGINT		0x0080
# define FL_QUADINT		0x0100
# define FL_PTRDIFF		0x0200
# define FL_SIZEINT		0x0400
# define FL_CHARINT		0x0800
# define FL_UPPER		0x1000
# define FL_SIGNED		0x2000

typedef struct	s_fmt
{
	char	type; //bit fields?
	int		flags; //bit fields?
	int		width_val;
	int		prec_val;
	size_t	param;
	size_t	width_pos;
	size_t	prec_pos;
}				t_fmt;

typedef struct	s_ptrs
{
	t_list *out_head;
	t_list *fmt_head;
	t_list *pos_head;
}				t_ptrs;

typedef struct	s_pos
{
	size_t	n;
	char	type; //bit fields?
	int		flags; //bit fields?
}				t_pos;

const char		*fmt_flags(const char *format, t_fmt *fmt);
int				fmt_pos_or_width(const char **format_p, t_fmt *fmt, t_list **pos_p);
int				fmt_aster(const char **format_p, t_fmt *fmt, t_list **pos_p, va_list ap);
int				fmt_dot(const char **format_p, t_fmt *fmt, t_list **pos_p, va_list ap);
void			fmt_lenght_and_type(const char **format_p, t_fmt *fmt);
int				fmt_width(long n, t_fmt *fmt);
void			fmt_upd_flags(int flag, t_fmt *fmt);
int				fmt_prec(long n, t_fmt *fmt);
int				fmt_set_prec(int value, unsigned long param, t_fmt *fmt);
int				fmt_pos(unsigned long n, char type, t_fmt *fmt, t_list **pos_p);
int				fmt_eoverflow(long n);
void			fmt_revise_flags(char type, t_fmt *fmt);

#endif
