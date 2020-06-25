/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:26:06 by skrasin           #+#    #+#             */
/*   Updated: 2020/05/19 10:21:37 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_size_t.h>
#include <sys/_types/_null.h>

void	ft_striteri(char *s, void (*f)(size_t, char *))
{
	size_t i;

	i = 0;
	if (s != NULL && f != NULL)
		while (*s != '\0')
			f(i++, s++);
}
