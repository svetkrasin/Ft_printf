/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 10:32:11 by svet              #+#    #+#             */
/*   Updated: 2020/03/08 06:07:27 by skrasin          ###   ########.fr       */
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

typedef struct	s_printf
{
	const char			*fmt;
	const char			*f;
	const char			*ch;
	int					n;
	int					param;
	int					flags;
	int					width;
	int					precision;
	int					lenght;
	int					done;
	int					save_errno;
	char				*fstr;
	va_list				ap_save;
}				t_printf;

int				ft_printf(const char *restrict format, ...);
int				ft_vfprintf(int fd, const char *restrict format, va_list ap,
													unsigned int mode_flags);
int				ft_vasprintf(char **result_ptr, const char *format,
																va_list args);
char			*ft_outstring(char **dst, char const *src, size_t len);
const char		*ft_strchrnul(const char *s, char c);
int				ft_check_ret(int curret, int newret);

#endif
