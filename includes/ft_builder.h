/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builder.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:13:16 by svet              #+#    #+#             */
/*   Updated: 2020/09/23 00:05:31 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILDER_H
# define FT_BUILDER_H
# include "../Libft/includes/libft.h"
# include "ft_parser.h"
# include "ft_getter.h"
# include <stdarg.h>
# include <_types/_uintmax_t.h>

int		build_out_node(t_dlist *out, t_argval argval, t_fmt *fmt);
int		build_out_pos(t_dlist *out_node, t_dlist *fmt_node, t_dlist *pos_head,
																	va_list ap);
int		build_fstr(char **fstr, t_dlist *out_node);

int		build_str(t_dlist *o, void *s, t_fmt f);
int		build_chr(t_dlist *out_node, int c, t_fmt fmt);
int		build_rand_chr(t_dlist *out_node, int c, t_fmt *fmt);
int		build_int(t_dlist *o, uintmax_t val, t_fmt f);
int		build_float(t_dlist *o, long double val, t_fmt f);
int		build_number(t_dlist *out, void *n, int flags);

char	*build_padding(int flags, int n);
int		build_latepadding(char **str, int flags, int n, int len);
int		build_intprefix(char **str, int flags, int minus, int base);
int		build_prependchar(char **str_p, char c);
int		build_str_error(char *str);

#endif
