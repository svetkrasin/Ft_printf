/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:25:53 by svet              #+#    #+#             */
/*   Updated: 2020/08/25 21:01:48 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include <sys/_types/_null.h>

void	fmt_revise_flags(char type, t_fmt *fmt)
{
	if (type == 'd' || type == 'i')
		fmt->flags |= FL_SIGNED;
	else if (type == 'p')
		fmt->flags |= FL_ALT | FL_SIZEINT;
	else if (ft_memchr("uoxXbUO", type, 7) != NULL)
	{
		fmt->flags &= ~(FL_SIGN | FL_SPACE);
		if (type == 'X')
			fmt->flags |= FL_UPPER;
		else if (type == 'U' || type == 'O')
			fmt->flags |= FL_LONGINT;
	}
	else if (ft_memchr("FEGA", type, 4) != NULL)
		fmt->flags |= FL_UPPER;
	else if (type == 'S' || type == 'C')
		fmt->flags |= FL_LONGINT;
	else if (type == 'P')
		fmt->flags |= FL_ALT | FL_UPPER | FL_SIZEINT;
	else if (type == 'D')
		fmt->flags |= FL_LONGINT | FL_SIGNED;
	fmt->type = type;
}

void	fmt_upd_flags(int flag, t_fmt *fmt)
{
	int flags;

	flags = fmt->flags;
	flags |= flag;
	if (flag & FL_LADJUST)
		flags &= ~FL_ZEROPAD;
	fmt->flags = flags;
}
