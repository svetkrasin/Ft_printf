/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 10:32:11 by svet              #+#    #+#             */
/*   Updated: 2020/06/24 17:25:32 by svet             ###   ########.fr       */
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

typedef struct	s_printf
{
	const char		*fmt;
	int				parametr;
	char			flags;
	unsigned long	width;
	unsigned long	precision;
	char			lenght;
	int				done;
	char			*fin_str;
	const char		*ch;
	int				save_errno;
	va_list			ap_save;
}				t_printf;

int				ft_printf(const char *restrict format, ...);
int				ft_vfprintf(int fd, const char *restrict format, va_list ap,
													unsigned int mode_flags);
int				ft_vasprintf(char **result_ptr, const char *format,
																va_list args);
int				ft_upd_ret(t_printf *node, int newret);
char			*ft_ultoa_base(unsigned long n, int base, int isupper);

int				ft_parse_type(t_printf *node);
void			ft_parse_param(t_printf *node);
void			ft_parse_length(t_printf *node);
void			ft_parse_flags(t_printf *node);
void			ft_parse_width(t_printf *node);
void			ft_parse_prec(t_printf *node);
int				ft_str_build(char *str, t_printf *node);
int				ft_int_build(uintmax_t val, int base, t_printf *node, int is_upper);
size_t			ft_unum_of_digs(unsigned long n, int base);

#endif
