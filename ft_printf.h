/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 10:32:11 by svet              #+#    #+#             */
/*   Updated: 2020/02/27 21:11:18 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "Libft/libft.h"

typedef struct	s_printf
{
	int					done;
	va_list				ap_save;
	int					param;
	char				flags;
	int					width;
	int					precision;
	int					length;
	char				type;
	char				*fstring;
	int					flen;
	const char			*format;
	const char			*thousands_sep;
	int					save_errno;
	const unsigned char	*f;
	const char			*grouping;
	const unsigned char	*lead_str_end;
	const unsigned char	*end_of_spec;

}				t_printf;

int				ft_printf(const char *restrict format, ...);
int				ft_vfprintf(int fd, const char *restrict format, va_list ap,
													unsigned int mode_flags);
int				ft_vasprintf(char **result_ptr, const char *format,
																va_list args);

#endif
