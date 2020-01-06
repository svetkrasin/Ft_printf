/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:57:29 by skrasin           #+#    #+#             */
/*   Updated: 2019/09/20 18:25:28 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	size_t n;

	n = ft_strlen(s1);
	while (*s2)
		s1[n++] = *s2++;
	s1[n] = '\0';
	return (s1);
}
