/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:18:10 by svet              #+#    #+#             */
/*   Updated: 2020/09/07 21:03:36 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETTER_H
# define FT_GETTER_H
# include "libft.h"
# include "ft_parser.h"
# include <stdarg.h>
# include <_types/_uintmax_t.h>
# include <sys/_types/_ptrdiff_t.h>

typedef union	u_argval
{
	unsigned char		val_char;
	unsigned short		val_short;
	unsigned int		val_int;
	unsigned long		val_long;
	unsigned long long	val_quad;
	uintmax_t			val_max;
	float				val_float;
	double				val_double;
	long double			val_long_double;
	size_t				val_size_t;
	ptrdiff_t			val_ptrdiff_t;
	void				*val_ptr_t;
}				t_argval;

t_argval		get_pos_value(size_t n, t_list *pos_node, va_list ap);
t_argval		get_argtype(char type, int length, va_list ap);
int				get_width(t_fmt *fmt, size_t n, t_list *pos_node, va_list ap);
int				get_prec(t_fmt *fmt, size_t n, t_list *pos_node, va_list ap);

#endif
