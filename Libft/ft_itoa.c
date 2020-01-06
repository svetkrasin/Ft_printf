/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:34:00 by skrasin           #+#    #+#             */
/*   Updated: 2019/10/08 14:54:36 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static size_t	ft_itoa_len(int n)
{
	size_t len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*ft_itoa_transfer(char *s, int len, int n)
{
	if (n == -2147483648)
	{
		n = -214748364;
		s[--len] = '8';
	}
	if (n < 0)
		n *= -1;
	while (--len + 1)
	{
		s[len] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	char		*s;
	size_t		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_itoa_len(n);
	if ((s = ft_strnew(len)))
	{
		s = ft_itoa_transfer(s, len, n);
		if (n < 0)
			s[0] = '-';
		return (s);
	}
	return (NULL);
}
