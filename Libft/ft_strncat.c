/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:00:53 by skrasin           #+#    #+#             */
/*   Updated: 2019/09/20 18:46:33 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *restrict s1, char *restrict s2, size_t n)
{
	size_t i;

	i = ft_strlen(s1);
	while (*s2 && n--)
		s1[i++] = *s2++;
	s1[i] = '\0';
	return (s1);
}
