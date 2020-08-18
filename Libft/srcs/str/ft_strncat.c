/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:00:53 by skrasin           #+#    #+#             */
/*   Updated: 2020/07/21 18:55:11 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	char *const		s = s1;
	const size_t	l = ft_strnlen(s2, n);

	s1 += ft_strlen(s1);
	s1[l] = '\0';
	ft_memcpy(s1, s2, l);
	return (s);
}
