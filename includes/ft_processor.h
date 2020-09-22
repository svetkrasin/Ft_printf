/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:24:53 by svet              #+#    #+#             */
/*   Updated: 2020/09/21 15:57:32 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESSOR_H
# define FT_PROCESSOR_H
# include "../Libft/includes/libft.h"
# include <stdarg.h>

int		fmt_proc(t_list *heads[3], const char *format, va_list ap);
void	pos_proc(t_list **pos_head_p, t_list *fmt_head);

#endif
