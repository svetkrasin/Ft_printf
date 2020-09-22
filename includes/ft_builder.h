/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builder.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:13:16 by svet              #+#    #+#             */
/*   Updated: 2020/09/21 15:57:55 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILDER_H
# define FT_BUILDER_H
# include "../Libft/includes/libft.h"
# include "ft_parser.h"
# include "ft_getter.h"
# include <stdarg.h>
# include <_types/_uintmax_t.h>

int		build_out_node(t_list *out, t_argval argval, t_fmt *fmt);
int		build_out_pos(t_list *out_node, t_list *fmt_node, t_list *pos_head,
																	va_list ap);
int		build_fstr(char **fstr, t_list *out_node);

int		build_str(t_list *o, void *s, t_fmt f);
int		build_chr(t_list *out_node, int c, t_fmt fmt);
int		build_rand_chr(t_list *out_node, int c, t_fmt *fmt);
int		build_int(t_list *o, uintmax_t val, t_fmt f);
int		build_float(t_list *o, long double val, t_fmt f);

char	*build_padding(int flags, int n);
int		build_latepadding(char **str, int flags, int n, int len);
int		build_intprefix(char **str, int flags, int minus, int base);
int		build_prependchar(char **str_p, char c);
int		build_str_error(char *str);

#endif
