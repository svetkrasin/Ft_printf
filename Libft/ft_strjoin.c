/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:51:23 by skrasin           #+#    #+#             */
/*   Updated: 2019/10/03 19:41:39 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fstr;
	size_t	n1;

	if (s1 && s2)
	{
		n1 = ft_strlen(s1);
		if ((fstr = ft_strnew(n1 + ft_strlen(s2) + 1)))
		{
			fstr = ft_memmove(fstr, s1, n1 + 1);
			return (ft_strcat(fstr, s2));
		}
	}
	return (NULL);
}
