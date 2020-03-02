/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 10:32:11 by svet              #+#    #+#             */
/*   Updated: 2020/03/02 06:12:19 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <sys/types.h>
# include <stddef.h>
# include <errno.h>
# include <limits.h>
# include "Libft/libft.h"
# include <sys/_types/_wint_t.h>
# define MAXEXPDIG 6
# define BUF 32
# define ALT 0x001
# define LADJUST 0x004
# define LONGDBL 0x008
# define LONGINT 0x010
# define LLONGINT 0x020
# define SHORTINT 0x040
# define ZEROPAD 0x080
# define FPT 0x100
# define GROUPING 0x200
# define SIZET 0x400
# define PTRDIFFT 0x800
# define INTMAXT 0x1000
# define CHARINT 0x2000
# define STATIC_ARG_TBL_SIZE 8

static const char	g_xdigs_lower[16] = "0123456789abcdef";
static const char	g_xdigs_upper[16] = "0123456789ABCDEF";

typedef struct	s_grouping_state
{
	char		*thousands_sep;
	int			thousep_len;
	const char	*grouping;
	int			lead;
	int			nseps;
	int			nrepeats;
}				t_grouping_state;

union	u_fparg
{
	double		dbl;
	long double	dbl;
};

// union	u_arg
// {
// 	int					intarg;
// 	u_int				uintarg;
// 	long				longarg;
// 	u_long				ulongarg;
// 	long long			longlongarg;
// 	unsigned long long	ulonglongarg;
// 	ptrdiff_t			ptrdiffarg;
// 	size_t				sizearg;
// 	intmax_t			intmaxarg;
// 	uintmax_t			uintmaxarg;
// 	void				*pvoidarg;
// 	char				*pchararg;
// 	signed char			*pschararg;
// 	short				*pshortarg;
// 	int					*pintarg;
// 	long				*plongarg;
// 	long long			*plonglongarg;
// 	ptrdiff_t			*pptrdiffarg;
// 	ssize_t				*pssizearg;
// 	intmax_t			*pintmaxarg;
// 	double				doublearg;
// 	long double			longdoublearg;
// 	wint_t				wintarg;
// 	wchar_t				*pwchararg;
// };

union	u_arg
{
	int				intarg;
	long			longarg;
	intmax_t		intmaxarg;
	double			doublearg;
	long double		longdoublearg;
	wint_t			wintarg;
	char			*pchararg;
	wchar_t			*pwchararg;
	void			*pvoidarg;
};

typedef struct	s_printf
{
	char				*fmt;
	int					ch;
	int					n;
	int					n2;
	char				*cp;
	int					flags;
	int					ret;
	int					width;
	int					prec;
	char				sign;
	t_grouping_state	gs;
	char				*decimal_point;
	int					decpt_len;
	int					signflag;
	union u_fparg		fparg;
	int					expt;
	char				expchar;
	char				*dtoaend;
	int					expsize;
	int					ndig;
	char				expstr[MAXEXPDIG + 2];
	char				*dtoaresult;
	u_long				ulval;
	uintmax_t			ujval;
	int					base;
	int					dprec;
	int					realsz;
	int					size;
	int					psize;
	const char			*xdigs;
	char				buf[BUF];
	char				ox[2];
	union u_arg			*argtable;
	union u_arg			statargtable[STATIC_ARG_TBL_SIZE];
	int					nextarg;
	va_list				orgap;
	char				*convbuf;
}				t_printf;

int				ft_printf(const char *restrict format, ...);
int				ft_vfprintf(int fd, const char *restrict format, va_list ap,
													unsigned int mode_flags);
int				ft_vasprintf(char **result_ptr, const char *format,
																va_list args);

#endif
