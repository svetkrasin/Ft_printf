/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 13:57:45 by svet              #+#    #+#             */
/*   Updated: 2020/09/09 18:18:37 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H
# include <sys/_types/_wchar_t.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isspace(int c);

int		ft_isnegative(int c);
int		ft_ispositive(int c);
int		ft_isbetween(int x, int m, int n);
char	*ft_wctomb(wchar_t c);

#endif
